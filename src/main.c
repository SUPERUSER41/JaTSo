#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct Record
{
    unsigned int key;
    char fname[25];
    char lname[25];
    unsigned int age;
} Record;

int OpenRecordUpdate(char *fileName)
{
    int fd;
    fd = open(fileName, O_CREAT | O_RDWR | O_APPEND, 0644);
    if (fd == -1)
    {
        perror("OpenRecord");
    }
    return fd;
}

int OpenRecord(char *fileName)
{
    int fd;
    fd = open(fileName, O_CREAT | O_RDWR | O_APPEND, 0644);
    if (fd == -1)
    {
        perror("OpenRecord");
    }
    return fd;
}

void CloseRecord(int fd)
{
    close(fd);
}

int InsertRecord(int fd, Record *rec)
{
    int ret;
    ret = write(fd, rec, sizeof(Record));
    return ret;
}

int GetRecord(int fd, Record *rec, int key)
{
    int ret;
    while ((ret = read(fd, rec, sizeof(Record))) != -1)
    {
        if (ret == 0)
        {
            memset(rec, 0, sizeof(Record));
            break;
            return ret;
        }
        else if (key == rec->key)
        {
            return ret;
        }
    }
    memset(rec, 0, sizeof(Record));
    return ret;
}

int DeleteRecord(int fd, int key)
{
    int ret;
    Record rec;
    off_t pos;
    pos = lseek(fd, 0, SEEK_SET);
    while ((ret = read(fd, &rec, sizeof(Record))) != -1)
    {
        if (ret == 0)
        {
            return ret;
        }
        else if (key == rec.key)
        {
            lseek(fd, pos, SEEK_SET);
            rec.key = 0;
            ret = write(fd, &rec, sizeof(Record));
            return ret;
        }
        pos = lseek(fd, 0, SEEK_CUR);
    }
    return ret;
}

int main(int argc, char *argv[])
{
    int fd;
    Record rec;

    fd = OpenRecord("records");

    if (argc > 1)
    {
        if (argc > 5 && !strcmp(argv[1], "insert"))
        {
            rec.key = atoi(argv[2]);
            strcpy(rec.fname, argv[3]);
            strcpy(rec.lname, argv[4]);
            rec.age = atoi(argv[5]);
            InsertRecord(fd, &rec);
        }
        if (argc > 2 && !strcmp(argv[1], "delete"))
        {
            DeleteRecord(fd, atoi(argv[2]));
        }
        if (argc > 2 && !strcmp(argv[1], "print"))
        {
            GetRecord(fd, &rec, atoi(argv[2]));
            printf("Key:\t\t%d\nFirst Name:\t\t%s\nLast Name:\t\t%s\nAge:\t\t%d\n", rec.key, rec.fname, rec.lname, rec.age);
        }
    }
    CloseRecord(fd);
    return 0;
}
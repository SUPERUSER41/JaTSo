#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int generateId(Participant *participants, Participant *p)
{
    int id = 0;
    for (p = participants; p; p = p->next)
    {
        id = p->id;
    }
    return id + 1;
}

Participant *createParticipant(int id, char *name, char *school, char gender, Date *dob)
{
    Participant *p = malloc(sizeof(Participant));
    if (p != NULL)
    {
        p->id = id;
        strcpy(p->name, name);
        strcpy(p->school, school);
        p->gender = gender;
        p->dob = *dob;
        p->next = NULL;
    }
    return p;
}

Participant *addParticipant(Participant **participants, Participant *p)
{
    p->next = *participants;
    *participants = p;
    return p;
}

void printAllParticipants(Participant *participants)
{
    Participant *p = participants;
    while (p != NULL)
    {
        char dob[10];
        sprintf(dob, "%d/%d/%d", p->dob.month, p->dob.day, p->dob.year);
        printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
        p = p->next;
    }
}

int getParticipantAge(int birthYear)
{
    int age = 0;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    if (birthYear != 0)
    {
        age = (currentTime->tm_year + MIN_YR) - birthYear;
    }
    return age;
}

void printParticipant(Participant *p)
{
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob.month, p->dob.day, p->dob.year);
    printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
}

void destroyParticipant(Participant *p)
{
    free(p);
}
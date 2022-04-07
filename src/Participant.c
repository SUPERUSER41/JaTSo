#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../headers/participant.h"
#include "../headers/date.h"
#include "../headers/competition.h"

const char *PARTICIPANT_FORMAT_OUT = "%d,%s,%s,%c,%d,%d,%d\n";
const char *PARTICIPANT_FORMAT_IN = "%d,%[^,],%[^,],%c,%d,%d,%d\n";

Participant InitParticipant()
{
    Participant p;
    Date dob;
    dob.day = 0;
    dob.month = 0;
    dob.year = 0;
    p.id = 0;
    strcpy(p.name, "");
    strcpy(p.school, "");
    p.gender = 'M';
    p.dob = &dob;
    strcpy(p.eventType, "");
    p.score = 0;
    p.RegisterParticipant = &RegisterParticipant;
    p.SaveParticipant = &SaveParticipant;
    p.GetAge = &GetAge;
    p.PrintParticipant = &PrintParticipant;
    p.DestroyParticipant = &DestroyParticipant;
    return p;
}
void RegisterParticipant(Participant *p, char *name, char *school, char gender, Date *dob)
{
    Competition c = InitCompetition();

    strcpy(p->name, name);
    strcpy(p->school, school);
    p->gender = gender;
    p->dob = dob;
    p->id = GenerateId(p);
    p->SaveParticipant(p);
    c.RegisterCompetition(&c, p);
}
void SaveParticipant(Participant *p)
{
    FILE *fp = fopen("./data/participants.txt", "a+");
    if (fp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    fprintf(fp, PARTICIPANT_FORMAT_OUT, p->id, p->name, p->school, p->gender, p->dob->month, p->dob->day, p->dob->year);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
}
int GetAge(Participant *p)
{
    int age = 0;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    if (p != NULL)
    {
        age = (currentTime->tm_year + MIN_YR) - p->dob->year;
    }
    return age;
}
int GenerateId(Participant *p)
{
    int id = 0;
    FILE *fp = fopen("./data/participants.txt", "r");
    if (fp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    while (fscanf(fp, PARTICIPANT_FORMAT_IN, &p->id, p->name, p->school, &p->gender, &p->dob->month, &p->dob->day, &p->dob->year) != EOF)
    {
        id = p->id;
    }
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
    return id + 1;
}
void PrintParticipant(Participant *p)
{
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);
    printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
}
void DestroyParticipant(Participant *p)
{
    p->RegisterParticipant = NULL;
    p->GetAge = NULL;
    p->DestroyParticipant = NULL;
}
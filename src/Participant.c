#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../headers/participant.h"
#include "../headers/date.h"
#include "../headers/competition.h"

Participant InitParticipant()
{
    Participant p;
    Date dob;
    dob.day = 0;
    dob.month = 0;
    dob.year = 0;
    p.id = 0;
    p.name = "";
    p.school = "";
    p.gender = 'M';
    p.dob = &dob;
    p.DestroyParticipant = &DestroyParticipant;
    p.RegisterParticipant = &RegisterParticipant;
    p.GetAge = &GetAge;
    p.PrintParticipant = &PrintParticipant;
    return p;
}
void RegisterParticipant(Participant *p, char *name, char *school, char gender, Date *dob)
{
    p->id = 0;
    p->name = name;
    p->school = school;
    p->gender = gender;
    p->dob = dob;
    int age = p->GetAge(p);
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
void PrintParticipant(Participant *p)
{
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);
    printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
}
void DestroyParticipant(Participant *p)
{
    p->RegisterParticipant = NULL;
    p->DestroyParticipant = NULL;
    p->dob = NULL;
}
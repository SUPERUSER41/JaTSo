#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/participant.h"
#include "../headers/date.h"

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
    p.Destroy = &Destroy;
    p.Register = &Register;
    return p;
}
void Register(Participant *p, char *name, char *school, char gender, Date *dob)
{
    p->id = 0;
    p->name = name;
    p->school = school;
    p->gender = gender;
    p->dob = dob;
}
void PrintParticipant(Participant *p)
{
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);
    printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
}
void Destroy(Participant *p)
{
    p->Register = NULL;
    p->Destroy = NULL;
    p->dob = NULL;
}
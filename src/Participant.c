#include <stdio.h>
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
}
void Register(Participant *p, char *name, char *school, char gender, Date *dob)
{
    p->name = name;
    p->school = school;
    p->gender = gender;
    p->dob = dob;
}
void Destroy(Participant *p)
{
    p->Register = NULL;
    p->Destroy = NULL;
    p->dob = NULL;
}
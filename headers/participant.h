#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "date.h"

typedef struct Participant
{
    int id;
    char *name;
    char *school;
    char gender;
    Date *dob;
    void (*Register)(struct Participant *p, char *name, char *school, char gender, Date *dob);
    int (*GetAge)(int birthYear);
    void (*PrintParticipant)(struct Participant *p);
    void (*Destroy)(struct Participant *p);
} Participant;

Participant InitParticipant();
void Register(Participant *p, char *name, char *school, char gender, Date *dob);
int GetAge(int birthYear);
void PrintParticipant(Participant *p);
void Destroy(Participant *p);
#endif
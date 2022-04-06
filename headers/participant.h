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
    void (*PrintParticipant)(struct Participant *p);
    void (*Destroy)(struct Participant *p);
} Participant;

Participant InitParticipant();
void Register(Participant *p, char *name, char *school, char gender, Date *dob);
void Destroy(Participant *p);
void PrintParticipant(Participant *p);
#endif
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
    void (*Register)(struct Participant *p, char *name, char *school, char gender, Date *dob;);
    void (*Destroy)(struct Participant *p);
} Participant;

static Participant InitParticipant();
static void Register(Participant *p, char *name, char *school, char gender, Date *dob);
static void Destroy(Participant *p);
#endif
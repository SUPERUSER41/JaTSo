#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "date.h"

typedef struct Participant
{
    int id;
    char name[25];
    char school[50];
    char gender;
    Date *dob;
    void (*RegisterParticipant)(struct Participant *p, char *name, char *school, char gender, Date *dob);
    void (*SaveParticipant)(struct Participant *p);
    int (*GetAge)(struct Participant *p);
    void (*PrintParticipant)(struct Participant *p);
    void (*DestroyParticipant)(struct Participant *p);
} Participant;

Participant InitParticipant();
void RegisterParticipant(Participant *p, char *name, char *school, char gender, Date *dob);
void SaveParticipant(Participant *p);
int GetAge(Participant *p);
int GenerateId(Participant *p);
void PrintParticipant(Participant *p);
void DestroyParticipant(Participant *p);
#endif
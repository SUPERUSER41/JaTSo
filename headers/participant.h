#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "date.h"

typedef struct Participant
{
    int id;
    char name[25];
    char gender;
    Date *dob;
    char school[25];
    char eventName[25];
    int score;
    int totalScore;
    int competitionId;
    void (*RegisterParticipant)(struct Participant *p);
    void (*SaveParticipant)(struct Participant *p);
} Participant;

Participant InitParticipant();
void RegisterParticipant(Participant *p);
void SaveParticipant(Participant *p);

#endif
#ifndef COMPETITION_H
#define COMPETITION_H

#include "participant.h"
typedef struct Competition
{
    char *name;
    int participantId;
    void (*RegisterCompetition)(struct Competition *c, Participant *p);
    void (*PrintCompetition)(struct Competition *c);
    void (*DestroyCompetition)(struct Competition *c);
} Competition;

Competition InitCompetition();
void RegisterCompetition(Competition *c, Participant *p);
void PrintCompetition(Competition *c);
void DestroyCompetition(Competition *c);
#endif
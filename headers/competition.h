#ifndef COMPETITION_H
#define COMPETITION_H

#include "participant.h"
typedef struct Competition
{
    char *name;
    void (*CreateCompetition)(struct Competition *c, char *name);
    void (*PrintCompetition)(struct Competition *c);
    void (*DestroyCompetition)(struct Competition *c);
} Competition;

Competition InitCompetition();
void CreateCompetition(Competition *c, char *name);
void PrintCompetition(Competition *c);
void DestroyCompetition(Competition *c);
#endif
#ifndef COMPETITION_H
#define COMPETITION_H

#include "participant.h"

typedef struct Competition
{
    char name[50];
    Participant *participants;
} Competition;

void printCompetition(Competition *c, int age);

Competition *createCompetition(int age, Participant *p);

#endif
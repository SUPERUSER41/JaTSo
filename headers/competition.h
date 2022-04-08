#ifndef COMPETITION_H
#define COMPETITION_H

typedef struct Competition
{
    int id;
    char name[25];
} Competition;

Competition InitCompetition();

#endif
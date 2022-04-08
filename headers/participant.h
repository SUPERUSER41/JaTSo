#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "date.h"
#include <stdbool.h>

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
    char competition[25];
    void (*RegisterParticipant)(struct Participant *p);
    void (*SaveParticipant)(struct Participant *p);
    int (*CalculateParticipantAge)(int birthYear);
    bool (*IsValidAge)(int age);
    void (*AssignCompetition)(int age, struct Participant *p);
    void (*PrintParticipant)(struct Participant *p);
} Participant;

Participant InitParticipant();
void RegisterParticipant(Participant *p);
void SaveParticipant(Participant *p);
int CalculateParticipantAge(int birthYear);
bool IsValidAge(int age);
void AssignCompetition(int age, Participant *p);
void PrintParticipant(Participant *p);
#endif
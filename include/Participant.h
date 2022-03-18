#ifndef PARTICIPANT_H
#define PARTICIPANT_H

typedef struct Participant
{
    int id;
} Participant;

Participant Participant_create(int id);

void Participant_print(Participant *self);

#endif
#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "date.h"

typedef struct Participant
{
    int id;
    char name[50];
    char school[50];
    char gender;
    Date dob;
    struct Participant *next;
} Participant;

// Create a participant
Participant *createParticipant(int id, char *name, char *school, char gender, Date *dob);

// Destroy a participant
void destroyParticipant(Participant *p);

// Get all participants
Participant *getAllParticipants();

// Get a single participant by their id
Participant *getParticipantById(int id);

// Print a single participant
void printParticipant(Participant *p);

// Print all participants
void printAllParticipants(Participant *participants);

// Get participant age
int getParticipantAge(int birthYear);

// Calculate participant time
void calculateParticipantTime();

// Generate a unique id number
int generateId(Participant *participants, Participant *p);

// Add a participant to a linked list
Participant *addParticipant(Participant **participants, Participant *p);

#endif
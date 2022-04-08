#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/participant.h"
#include "../headers/date.h"

const char *PARTICIPANT_FORMAT_OUT = "%d,%s,%c,%s,%s,%d,%d,%d\n";
const char *PARTICIPANT_FORMAT_IN = "%d,%[^,],%[^,],%c,%s\n";

Participant InitParticipant()
{
    Participant p;
    Date *dob = malloc(sizeof(Date));
    p.id = 0;
    p.score = 0;
    p.totalScore = 0;
    p.competitionId = 0;
    p.gender = 'M';
    p.dob = dob;
    strcpy(p.name, "");
    strcpy(p.school, "");
    strcpy(p.eventName, "");
    p.RegisterParticipant = &RegisterParticipant;
    p.SaveParticipant = &SaveParticipant;
    return p;
}

void RegisterParticipant(Participant *p)
{

    printf("Enter name:\n");
    scanf("%[^\n]s", p->name);
    printf("Enter gender:\n");
    scanf(" %c", &p->gender);
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &p->dob->month, &p->dob->day, &p->dob->year);
    printf("Enter school:\n");
    scanf("%[^\n]s", p->school);

    p->SaveParticipant(p);
}

void SaveParticipant(Participant *p)
{
    FILE *fp;
    fp = fopen("./data/participants.csv", "a+");
    if (fp == NULL)
    {
        perror("SaveParticipant");
        exit(1);
    }
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);
    fprintf(fp, PARTICIPANT_FORMAT_OUT, p->id, p->name, p->gender, dob, p->school, p->competitionId, p->score, p->totalScore);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../headers/participant.h"
#include "../headers/date.h"

//[id, name, gender, dob, school, competition, swimTime, cycleTime, runTime, score, totalScore]
const char *PARTICIPANT_FORMAT_OUT = "%d,%s,%c,%s,%s,%s,%d,%d,%d,%d\n";
const char *PARTICIPANT_FORMAT_IN = "%d,%[^,],%c,%[^,],%[^,],%[^,],%d,%d,%d,%d\n";

const char *KIDS_OF_STEEL = "Kids of Steel";
const char *IRON_KIDS = "Iron Kids";
const char *CAST_IRON_KIDS = "Cast Iron Kids";

Participant InitParticipant()
{
    Participant p;
    Date *dob = malloc(sizeof(Date));
    p.id = 0;
    p.totalScore = 0;
    p.swimTime = 0;
    p.runTime = 0;
    p.cycleTime = 0;
    p.gender = 'M';
    p.dob = dob;
    strcpy(p.name, "");
    strcpy(p.school, "");
    strcpy(p.competition, "Kids of Steel");
    p.RegisterParticipant = &RegisterParticipant;
    p.SaveParticipant = &SaveParticipant;
    p.CalculateParticipantAge = &CalculateParticipantAge;
    p.IsValidAge = &IsValidAge;
    p.AssignCompetition = &AssignCompetition;
    p.PrintParticipant = &PrintParticipant;
    p.GenerateId = &GenerateId;
    p.SearchParticipant = &SearchParticipant;
    return p;
}

void RegisterParticipant(Participant *p)
{
    clrscr();
    fflush(stdin);
    printf("Enter name:\n");
    scanf("%[^\n]s", p->name);
    printf("Enter gender:\n");
    scanf(" %c", &p->gender);
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &p->dob->month, &p->dob->day, &p->dob->year);
    int age = p->CalculateParticipantAge(p->dob->year);
    bool isValidAge = p->IsValidAge(age);
    if (isValidAge)
    {
        p->AssignCompetition(age, p);
    }
    fflush(stdin);
    printf("Enter school:\n");
    scanf("%[^\n]s", p->school);
    pause();
    p->id = p->GenerateId(p);
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
    //[id, name, gender, dob, school, competition, swimTime, cycleTime, runTime, score, totalScore]
    fprintf(fp, PARTICIPANT_FORMAT_OUT, p->id, p->name, p->gender, p->school, dob, p->competition, p->swimTime, p->cycleTime, p->runTime, p->totalScore);
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
}
int CalculateParticipantAge(int birthYear)
{
    int age = 0;
    time_t t = time(NULL);
    struct tm *currentTime = localtime(&t);
    if (birthYear != 0)
    {
        age = (currentTime->tm_year + MIN_YR) - birthYear;
    }
    return age;
}

bool IsValidAge(int age)
{
    bool isValid = false;
    if ((age >= 6 && age <= 8) || (age >= 9 && age <= 11) || (age >= 12 && age <= 15))
    {
        isValid = true;
    }
    return isValid;
}

void AssignCompetition(int age, Participant *p)
{
    if (age >= 6 && age <= 8)
    {
        strcpy(p->competition, KIDS_OF_STEEL);
    }
    else if (age >= 9 && age <= 11)
    {
        strcpy(p->competition, IRON_KIDS);
    }
    else if (age >= 12 && age <= 15)
    {
        strcpy(p->competition, CAST_IRON_KIDS);
    }
}

int GenerateId(Participant *p)
{
    int id = 0;
    FILE *fp = fopen("./data/participants.csv", "r");
    if (fp == NULL)
    {
        printf("The file could not be opened\n");
        exit(1);
    }
    char dob[10];
    //[id, name, gender, dob, school, competition, swimTime, cycleTime, runTime, totalScore]
    while (fscanf(fp, PARTICIPANT_FORMAT_IN, &p->id, p->name, &p->gender, dob, p->school, p->competition, &p->swimTime, &p->cycleTime, &p->runTime, &p->totalScore) != EOF)
    {
        id = p->id;
    }
    fclose(fp);
    return id + 1;
}

void SearchParticipant()
{
    Participant p;
    int id;
    bool isFound = false;
    FILE *fp = fopen("./data/participants.csv", "r");

    clrscr();
    printf("Enter id to search:\n");
    scanf("%d", &id);

    while (fscanf(fp, PARTICIPANT_FORMAT_OUT, &p.id, p.name, p.school, &p.gender, &p.dob->month, &p.dob->day, &p.dob->year) != EOF)
    {
        if (p.id == id)
        {
            isFound = true;
            PrintParticipant(&p);
        }
    }

    if (!isFound)
    {
        printf("Participant cannot be found\n");
        pause();
    }
    fseek(fp, 0, SEEK_SET);
    fclose(fp);
}

void PrintParticipant(Participant *p)
{
    clrscr();
    char dob[10];
    sprintf(dob, "%d/%d/%d", p->dob->month, p->dob->day, p->dob->year);
    printf("Id:\t\t%d\nName:\t\t%s\nSchool:\t\t%s\nGender:\t\t%c\nDob:\t\t%s\n", p->id, p->name, p->school, p->gender, dob);
    pause();
}

void PrintBestTriathlete()
{
    clrscr();
    printf("======================================================================");
    printf("Swimming\t\tCycling\t\tRunning\t\t");
    printf("======================================================================");
    pause();
}

void pause()
{
    system("read -n1 -r -p \"Press any key to continue...\" key");
}

void clrscr()
{
    system("@cls||clear");
}
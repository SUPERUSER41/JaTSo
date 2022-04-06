#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/competition.h"

Competition *createCompetition(int age, Participant *p)
{
    Competition *c = malloc(sizeof(Competition));
    if (c != NULL)
    {
        if (age >= 6 && age <= 8)
        {
            strcpy(c->name, "Kids of steel");
        }
        else if (age >= 9 && age <= 11)
        {
            strcpy(c->name, "Iron Kids");
        }
        else if (age >= 12 && age <= 15)
        {
            strcpy(c->name, "Cast Iron Kids");
        }
        c->participants = p;
    }
    return c;
}

void printCompetition(Competition *c, int age)
{
    printf("-------------------------\n");
    printf("\tCompetition\n");
    printf("-------------------------\n");
    printf("Participant:\t\t%s\nAge:\t\t%d\nCompetition:\t\t%s\n", c->participants->name, age, c->name);
}
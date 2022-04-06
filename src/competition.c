#include <stdio.h>
#include "../headers/competition.h"

Competition InitCompetition()
{
    Competition c;
    c.name = "";
    c.CreateCompetition = &CreateCompetition;
    c.PrintCompetition = &PrintCompetition;
    c.DestroyCompetition = &DestroyCompetition;
    return c;
}
void CreateCompetition(Competition *c, char *name)
{
    c->name = name;
}
void PrintCompetition(Competition *c)
{
    printf("Name:\t\t%s\n", c->name);
}
void DestroyCompetition(Competition *c)
{
    c->CreateCompetition = NULL;
    c->DestroyCompetition = NULL;
}
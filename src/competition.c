#include <stdio.h>
#include "../headers/competition.h"
#include "../headers/participant.h"

Competition InitCompetition()
{
    Competition c;
    c.name = "";
    c.participantId = 0;
    c.RegisterCompetition = &RegisterCompetition;
    c.PrintCompetition = &PrintCompetition;
    c.DestroyCompetition = &DestroyCompetition;
    return c;
}
void RegisterCompetition(Competition *c, Participant *p)
{
    int age = p->GetAge(p);

    if (age >= 6 && age <= 8)
    {
        c->name = "Kids of Steel";
        c->participantId = p->id;
        p->PrintParticipant(p);
    }
    else if (age >= 9 && age <= 11)
    {
        c->name = "Iron Kids";
        c->participantId = p->id;
        p->PrintParticipant(p);
    }
    else if (age >= 12 && age <= 15)
    {
        c->name = "Cast Iron Kids";
        c->participantId = p->id;
        p->PrintParticipant(p);
    }
    else
    {
        printf("Participant is too old.\n");
    }
}
void PrintCompetition(Competition *c)
{
    printf("Name:\t\t%s\n", c->name);
}
void DestroyCompetition(Competition *c)
{
    c->RegisterCompetition = NULL;
    c->DestroyCompetition = NULL;
}
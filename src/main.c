#include <stdio.h>
#include <stdlib.h>
#include "../headers/participant.h"
#include "../headers/competition.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    p.RegisterParticipant(&p);
    p.PrintParticipant(&p);
    return 0;
}
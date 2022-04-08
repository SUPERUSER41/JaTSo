#include <stdio.h>
#include <string.h>
#include "../headers/competition.h"

Competition InitCompetition()
{
    Competition c;
    c.id = 0;
    strcpy(c.name, "");
    return c;
}
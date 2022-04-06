#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    Date dob = {.day = 26, .month = 2, .year = 1998};
    p.RegisterParticipant(&p, "Daneil Greaves", "Mona High School", 'M', &dob);
    p.PrintParticipant(&p);
    p.DestroyParticipant(&p);
    return 0;
}
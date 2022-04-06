#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    Date dob = {.day = 26, .month = 2, .year = 2007};
    p.RegisterParticipant(&p, "Daneil Greaves", "Mona High School", 'M', &dob);
    p.DestroyParticipant(&p);
    return 0;
}
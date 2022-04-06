#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    Date dob = {.day = 26, .month = 2, .year = 1998};
    p.Register(&p, "Daneil Greaves", "Mona High School", 'M', &dob);
    p.PrintParticipant(&p);
    int age = p.GetAge(&p);
    p.Destroy(&p);
    return 0;
}
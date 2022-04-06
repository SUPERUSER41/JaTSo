#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    Date dob = {.day = 1, .month = 1, .year = 2007};
    p.RegisterParticipant(&p, "John Doe", "Mona High School", 'M', &dob);
    p.DestroyParticipant(&p);
    return 0;
}
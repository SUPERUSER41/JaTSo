#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    Participant p = InitParticipant();
    Date dob = InitDate();
    printf("Enter name:\n");
    scanf("%s", p.name);
    printf("Enter school:\n");
    scanf("%s", p.school);
    printf("Enter gender:\n");
    scanf(" %c", &p.gender);
    printf("Enter date of birth (mm/dd/yyyy):\n");
    scanf("%d/%d/%d", &dob.month, &dob.day, &dob.year);
    p.RegisterParticipant(&p, "John Doe", "Mona High School", 'M', &dob);
    p.DestroyParticipant(&p);
    return 0;
}
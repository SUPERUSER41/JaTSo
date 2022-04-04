#include <stdio.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{

    Participant p, *participant = NULL, *participants = NULL;

    fflush(stdin);
    printf("Enter name:\n");
    scanf("%[^\n]s", p.name);

    printf("Enter gender(M/F):\n");
    scanf(" %c", &p.gender);

    printf("Enter date of birth:(mm/dd/yyyy)\n");
    scanf("%d/%d/%d", &p.dob.month, &p.dob.day, &p.dob.year);

    fflush(stdin);
    printf("Enter school:\n");
    scanf("%[^\n]s", p.school);

    int id = generateId(participants, participant);
    participant = createParticipant(id, p.name, p.school, p.gender, &p.dob);
    addParticipant(&participants, participant);
    printAllParticipants(participants);

    // int age = getParticipantAge(participant->dob.year);

    return 0;
}
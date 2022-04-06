#include <stdio.h>
#include <stdlib.h>
#include "../headers/participant.h"
#include "../headers/date.h"
#include "../headers/competition.h"

void pause()
{
    system("read -n1 -r -p \"Press any key to continue...\" key");
}

void clrscr()
{
    system("@cls||clear");
}

void registerParticipant()
{
    Participant p, *participant = NULL, *participants = NULL;
    Competition *competition;

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
    clrscr();
    printAllParticipants(participants);

    int age = getParticipantAge(participant->dob.year);

    competition = createCompetition(age, participant);
    printCompetition(competition, age);

    // TODO: enter time for a participant for a particular event

    pause();
}

void registerParticipantTime()
{
    int event, id;
    printf("Enter participant id:\n");
    scanf("%d", &id);
    // TODO: search participant
    do
    {
        clrscr();
        printf("-------------------------\n");
        printf("\tSelect Event\n");
        printf("-------------------------\n");
        printf("1. Swimming\n");
        printf("2. Cycling\n");
        printf("3. Running\n");
        printf("0. Back\n");
        printf("Enter your choice: \n");
        scanf("%d", &event);
        switch (event)
        {
        case 1:
            printf("Enter time for swimming event:\n");
            scanf("%d", &time);
            p.time = time;
            break;
        case 2:
            printf("Enter time for swimming event:\n");
            scanf("%d", &time);
            p.time = time;
            break;
        case 3:
            printf("Enter time for swimming event:\n");
            scanf("%d", &time);
            p.time = time;
            break;
        }
    } while (event != 0);
}

void menu()
{
    int ch1, ch2, ch3;
    do
    {
        clrscr();
        printf("-------------------------\n");
        printf("\tMain Menu\n");
        printf("-------------------------\n");
        printf("1. Manage Competition\n");
        printf("2. Manage Participant\n");
        printf("0. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            do
            {
                clrscr();
                printf("-----------------------------------\n");
                printf("\tManage Competition\n");
                printf("-----------------------------------\n");
                printf("1. Display Report\n");
                printf("0. Back\n");
                printf("Enter your choice:\n");
                scanf("%d", &ch2);
            } while (ch2 != 0);
            break;

        case 2:
            do
            {
                clrscr();
                printf("-----------------------------------\n");
                printf("\tManage Participant\n");
                printf("-----------------------------------\n");
                printf("1. Register Participant\n");
                printf("2. Search Participants\n");
                printf("3. Enter Participant Time\n");
                printf("0. Back\n");
                printf("Enter your choice:\n");
                scanf("%d", &ch3);
                switch (ch3)
                {
                case 1:
                    clrscr();
                    registerParticipant();
                    break;

                case 2:
                    // TODO: searchParticipant();
                    break;
                case 3:
                    registerParticipantTime();
                    break;
                }
            } while (ch3 != 0);
            break;
        }

    } while (ch1 != 0);
}

int main()
{
    menu();
    return 0;
}
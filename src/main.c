#include <stdio.h>
#include <stdlib.h>
#include "../headers/participant.h"
#include "../headers/date.h"

int main()
{
    int ch1;
    Participant p = InitParticipant();
    do
    {
        clrscr();
        printf("-------------------------\n");
        printf("\tMain Menu\n");
        printf("-------------------------\n");
        printf("1. Register Participant\n");
        printf("2. View Participant\n");
        printf("3. Enter Participant time\n");
        printf("4. View Best Participant\n");
        printf("5. View Winner For Each Competition\n");
        printf("0. Exit\n");
        scanf("%d", &ch1);
        switch (ch1)
        {
        case 1:
            p.RegisterParticipant(&p);
            break;
        case 2:
            p.PrintParticipant(&p);
            break;
        case 3:
            printf("Enter participant time:\n");
            break;
        case 4:
            printf("Display results:\n");
            break;
        case 5:
            printf("Display results:\n");
            break;
        }
    } while (ch1 != 0);
    return 0;
}
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
        }
    } while (ch1 != 0);
    return 0;
}
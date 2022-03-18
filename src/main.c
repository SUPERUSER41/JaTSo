#include <stdio.h>

//Function prototypes
int generateId(void);
void printParticipantDetails(void);
void printWelcomeMessage(void);

enum Gender {MALE, FEMALE} Gender;
enum Event {RUNNING, CYCLING, SWIMMING} Event;

// struct Dob{
//     int year;
//     int month;
//     int day;
// }

struct Participant
{
    int id;
    char name[50];
    char school[50];
    int dob;
    int score;
    char gender;
    enum Event event;
}participant;

int main(){

    printWelcomeMessage();

    createParticipant();

    printParticipantDetails();
   
    return 0;
}

void createParticipant()
{
    //Participant Struct initialization
    participant.score = 0;
    participant.id = generateId();

    printf("Enter name:\n");
    scanf("%s", participant.name);

    printf("Enter school/club:\n");
    //TODO: validate school input
    scanf("%s", participant.school);

    printf("Select your gender (M/F):\n");
    //TODO: validate gender input
    scanf(" %c", &participant.gender);

    //TODO: accept the participant event as char
    //TODO: research how to accept input with enums for example gender
    //TODO: research how to create a select option menu in c
}

//TODO: create a function to calculate age

//Generate Participant ID
int generateId()
{
    int count = 0;
    count = count + 1;
    return count;
}

//Print Participant Details
void printParticipantDetails()
{
    //TODO: Print the datails in a table
    if(participant.name != '\0' && participant.school != '\0')
    {
        printParticipantDetailsTable();
        printf("Participant id: %d\n", participant.id);
        printf("Participant name: %s\n", participant.name);
        printf("Participant school: %s\n", participant.school);
        printf("Participant score: %d\n", participant.score);
        printf("Participant gender: %c\n", participant.gender);
    }
    //TODO: validate gender & score
}

void printWelcomeMessage()
{
    printf("----------------Welcome----------------\n");
    printf("----------------To the--------------------\n");
    printf("---------------JAMAICA-----------------\n");
    printf("----TRIATHLON ASSOCIATION------\n");
}


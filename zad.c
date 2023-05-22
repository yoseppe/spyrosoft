#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define UPALJENO 1
#define UGASENO 0

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

bool states[3] = {UPALJENO, UPALJENO, UPALJENO};
int statesLength = sizeof(states)/sizeof(states[0]);

void printCurrentStates(bool A, bool B, bool C) {
    if (A == UPALJENO)
        printf("A upaljeno\n");
    else
        printf("A ugaseno\n");

    if (B == UPALJENO)
        printf("B upaljeno\n");
    else
        printf("B ugaseno\n");

    if (C == UPALJENO)
        printf("C upaljeno\n");
    else
        printf("C ugaseno\n");

    printf("---------------\n");
}

void startTurnOff(int index) {
    printCurrentStates(states[0], states[1], states[2]);
    delay(2);
    for(int i = index; i < statesLength; i++) {
        states[i] = UGASENO;
        printCurrentStates(states[0], states[1], states[2]);
        delay(2);
    }

    for(int i = index; i < statesLength; i++) {
        states[i] = UPALJENO;
        printCurrentStates(states[0], states[1], states[2]);
        delay(2);
    }
    
    return;
}

int main(void) {
    char x;
    int c = 1;
    printf("statesLength = %d\n", statesLength);
    printCurrentStates(states[0], states[1], states[2]);
    while(1) {
        printf("## iteracija %d\n", c++);
        printf("Unesi zeljeno stanje: ");
        scanf("%c", &x);
        printf("Procitano zeljeno stanje: %c\n", x);

        if(x == 'A') {
            startTurnOff(0);
        }
        else if(x == 'B') {
            startTurnOff(1);
        } else if(x == 'C') {
            startTurnOff(2);
        } else
            printf("Krivi unos. Dozvoljeno je A, B i C.\n");
        scanf("%c", &x);
    }

    return 0;
}
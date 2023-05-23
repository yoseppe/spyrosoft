#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
#define UPALJENO 1
#define UGASENO 0

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono; // ns, us, ms, s, h, etc.

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
    sleep_for(seconds(2));
    for(int i = index; i < statesLength; i++) {
        states[i] = UGASENO;
        printCurrentStates(states[0], states[1], states[2]);
        sleep_for(seconds(2));
    }

    for(int i = index; i < statesLength; i++) {
        states[i] = UPALJENO;
        printCurrentStates(states[0], states[1], states[2]);
        sleep_for(seconds(2));
    }
    
    return;
}

int main(void) {
    char x;
    int c = 1;
    cout << "yes";
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
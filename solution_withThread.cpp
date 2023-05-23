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

void printCurrentStates() {
    while(true) {
        if (states[0] == UPALJENO)
            printf("\nA upaljeno\n");
        else
            printf("\nA ugaseno\n");
    
        if (states[1] == UPALJENO)
            printf("B upaljeno\n");
        else
            printf("B ugaseno\n");
    
        if (states[2] == UPALJENO)
            printf("C upaljeno\n");
        else
            printf("C ugaseno\n");
    
        printf("---------------\n");
        sleep_for(seconds(5));
    }
}

void startTurnOff(int index) {
    for(int i = index; i < statesLength; i++) {
        states[i] = UGASENO;
        sleep_for(seconds(2));
    }

    for(int i = index; i < statesLength; i++) {
        states[i] = UPALJENO;
        sleep_for(seconds(2));
    }
    
    return;
}

void handler() {
    char x;
    while(true) {
        scanf("%c", &x);
        printf("Gasenje %c\n", x);

        if(x == 'A') {
            startTurnOff(0);
        }
        else if(x == 'B') {
            startTurnOff(1);
        }
        else if(x == 'C') {
            startTurnOff(2);
        }
        else {
            printf("Krivi unos. Dozvoljeno je A, B i C.\n");
        }
    }
}

int main(void) {
    thread printing(printCurrentStates);
    thread takingInput(handler);
    printing.join();
    takingInput.join();

    return 0;
}
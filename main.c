#include <stdio.h>
#include "process1.c"

#define HIT_RATE            0.5
#define WR_RATE             0.5

//system properties
#define N 5
#define USED_SLOTS_TH 3

//TIMES IN ns
#define SIM_TIME                    1
#define TIME_BETWEEN_SNAPSHOTS      100000000
#define MEM_WR_T                    1000
#define HD_ACCESS_T                 100000
#define INTER_MEM_ACCESS_T          10000


enum access_mode {
    READ,
    WRITE
};

_Noreturn int process1() {
    srand(time(NULL)); //CHECK RANDOM TIME
    while (1) {
        // wait for INTER_MEM_ACCS_T
        struct timespec req = {0, INTER_MEM_ACCS_T};
        nanosleep(&req, NULL);

        // determine if access is read or write
        enum access_mode mode;
        double r = (double)rand() / RAND_MAX;
        if (r < WR_RATE) {
            mode = WRITE;
        } else {
            mode = READ;
        }

        // send request to MMU
        // TODO comlete this

        printf("Sending %s request to MMU\n", mode == READ ? "read" : "write");


        // wait for ack from MMU
        // TODO comlete this

        // ...

    }
}

int main() {
    printf("Hello, World!\n");

    process1();
    return 0;
}


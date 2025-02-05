#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

volatile sig_atomic_t num = 3;
volatile int counter = 0;

void sigint_handler(int sig){
    counter++;
    printf("Caught a sigint: Press ctrl-c %d more times to exit", 3 - counter);
    if (counter >= 3) {
        printf("I've been banished!");
        exit(0);
    }
}

int main(){

    printf("We have a ctrl-c handler here!\n");
    signal(SIGINT, sigint_handler);
    while(1){
        printf("beep boop\n");
        sleep(1);
    }

    return 0;
}
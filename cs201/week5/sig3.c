#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

volatile sig_atomic_t num = 3;
volatile int counter = 0;

void sigint_handler(int sig){
    if (num > 0){
        printf("\nCaught that sigint!\n");
        printf("Detonation in... %d\n", num);
        num--;
    }
    else {
        printf("**Explosion noises**\n");
        exit(0);
    }
    counter++;
    printf("Caught a sigint: Press ctrl-c %d more times to exit\n", 3 - counter);
    if (counter >= 3) {
        printf("I've been banished!\n");
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
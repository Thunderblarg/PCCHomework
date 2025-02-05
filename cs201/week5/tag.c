#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

volatile sig_atomic_t num = 0;

void handler1(int sig){
    // this will be for the child receiving sigusr1
    printf("I've been tagged by my parent %d times\n", num);
    // fflush(stdout);
}

void handler2(int sig){
    printf("I've been tagged by my child %d times\n", num);
    // fflush(stdout);
}

int main(){
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);

    int pid = fork();

    if(pid < 0){
        return 1;
    }
    else if (pid == 0){
        // child logic
        signal(SIGUSR1, handler1);
        while(num < 5){
            kill(getppid(), SIGUSR2);
            sleep(1);
        }
        return 0;
    }
    else {
        // parent logic
        signal(SIGUSR2, handler2);
        while (num < 10)
        {
            kill(pid, SIGUSR1);
            sleep(1);
        }
        kill(pid, SIGTERM);
        wait(0);
    }
    return 0;
}
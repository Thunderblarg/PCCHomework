#include <stdio.h>
#include <signal.h>
#include <unistd.h>    
#include <stdlib.h>

int main(){
    
    // sigset_t blocks;
    // sigset_t prevs; // This is the type for the signal blocking flags
    

    // sigemptyset(&blocks); // set the blocks to the empty set
    // sigaddset(&blocks, SIGSTOP); // add sigstop to the blocked signals
    // sigprocmask(SIG_BLOCK, &blocks, &prevs); // the last is an optional argument to save what the previous state of the blocked signals data type was
    
    signal(SIGSTOP, handler);
    

    while (1) {
        printf("Here I am! %d\n", getpid());
        sleep(1);
    }

    return 0;
}
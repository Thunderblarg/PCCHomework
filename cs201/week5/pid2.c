#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

int main(){
    pid_t pid = fork(); // Generate a new process

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0){
        // This is the child process
        printf("Hello from the child process! My PID is %d\n", getpid());
        // getpid()     <- returns my pid
        // getppid()    <- returns parent pid
    }
    else {
        // This is the parent process
        wait(NULL);
        printf("hello from the parent process! My child's PID is %d\n", getpid());
    }

    // Both processes reach this and print a message
    printf("This message is printed by both the parent and the child.\n");
}
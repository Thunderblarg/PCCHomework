#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

int main(){
    pid_t pid = fork(); // Generate a new process
    int childReturn;

    if(pid < 0){
        perror("Fork failed");
        return 1;
    }
    else if(pid==0){
        printf("Hey, give me a number, will ya? ");
        int num;
        int success = scanf("%d", &num);
        
        if(success){
            return 0;
        }
        else {
            return 2;
        }
    }
    else {
        wait(&childReturn);
        printf("Here's the int returned by childReturn: %d\n", WEXITSTATUS(childReturn)); //(childReturn >> 8) & 255); 
        if(WEXITSTATUS(childReturn) == 0){
            printf("Thanks for being nice to my child\n");
        }
        else {
            printf("Look at how they massacred my boy\n");
        }
        return 0;
    }

}

    // if (pid < 0) {
    //     // Fork failed
    //     perror("Fork failed");
    //     return 1;
    // }
    // else if (pid == 0){
    //     // This is the child process
    //     printf("Hello from the child process! My PID is %d\n", getpid());
    //     // getpid()     <- returns my pid
    //     // getppid()    <- returns parent pid
    // }
    // else {
    //     // This is the parent process
    //     printf("hello from the parent process! My child's PID is %d\n", getpid());
    // }

    // // Both processes reach this and print a message
    // printf("This message is printed by both the parent and the child.\n");
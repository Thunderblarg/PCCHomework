#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // Need the UNIX standard library
#include <sys/types.h>  // Types defined by the operating system
#include <sys/wait.h>   // We need the wait command

int main(){

    printf("Hello! My id is %d and and my parent's id is %d\n", getpid(), getppid());

    return 0;
}
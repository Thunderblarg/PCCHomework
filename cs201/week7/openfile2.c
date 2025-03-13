#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

int echoFile(char* fName, bool showSize){
    
    int fd = open(fName, O_RDONLY);

    char buffer[1024] = {0};
    ssize_t bytesRead = 0;

    bytesRead = read(fd, buffer, sizeof(buffer));

    if(showSize){
        struct stat fileStat;
        lstat(fName, &fileStat);
        printf("The file %s is %ld bytes long and here it is:\n", fName, fileStat.st_size);
        bytesRead = read(fd, buffer, sizeof(buffer));

        if(bytesRead < 0){
            printf("Something went wrong (and you should feel bad)\n");
            return 1;
        }

        while(bytesRead > 0){
            write(STDOUT_FILENO, buffer, bytesRead);
            bytesRead = read(fd, buffer, sizeof(buffer));
        }

        close(fd);
        return 1;
    }
    


    return 0;
}

int main(int argc, char* argv[]){
    // // printf("We got %d arguments\n", argc);
    // // printf("Here's the first argument: %s\n", argv[0]);

    // char* fName = argv[1];
    // int fd = open(fName, O_RDONLY);

    // char buffer[1024] = {0};
    // ssize_t bytesRead = 0;

    // bytesRead = read(fd, buffer, sizeof(buffer));

    // if(bytesRead < 0){
    //     printf("Something went wrong (and you should feel bad)\n");
    //     return 1;
    // }

    // while(bytesRead > 0){
    //     write(STDOUT_FILENO, buffer, bytesRead);
    //     bytesRead = read(fd, buffer, sizeof(buffer));
    // }

    // close(fd);

    // change this so that if you pass in a -s argument
    // then it also prings the size using lstat

    if(strcmp(argv[1], "-s") == 0){
        echoFile(argv[2], true);
    }
    else {
        
    }

    return 0;
}
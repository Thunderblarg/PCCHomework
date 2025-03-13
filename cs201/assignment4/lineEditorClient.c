#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>      
#include <arpa/inet.h>   
#include <sys/socket.h>
#include <sys/types.h>

const int linesize = 1024;

#define port  8080
#define bsize 1024

int main(int argc, char* argv[]){
    int sock = 0;
    struct sockaddr_in servAddr;
    
    // char *filename = argv[1];
    char *filename = "boof.txt";

    sock = socket(AF_INET, SOCK_STREAM, 0);

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);

    inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr);

    connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr));

    write(sock, filename, strlen(filename)); // sending the filename

    printf("Contents of '%s':\n", filename);
    while (1) {
        // ssize_t bytesReceived = fgets(sock, buffer, bsize - 1); // reading the file
        char buffer[bsize] = {0};
        fgets(sock, buffer, bsize - 1); // reading the file

        if (strlen(buffer) == 0) {
            // No more data
            break;
        }
        // buffer[s] = '\0'; // Null-terminate the buffer
        int n = 0;
        printf("Line %d: %s", n++, buffer);
    }
    printf("\n");
}
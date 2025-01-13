#include <stdio.h>
#include <stdlib.h>

// are we big endian?
// or little endian?

int main() {
    // every 2 hex digits is an 8-bit byte
    int num = 0x12345678;

    unsigned char* pointy = &num;

    printf("Out number's bytes, in order, are: \n");
    for (int i = 0; i < sizeof(int); i++) {
        printf(" %x \n", *(pointy + i));
        
    }

    return 0;
}
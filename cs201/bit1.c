#include <stdio.h>
#include <stdlib.h>

void printBits(int num) {
    // an int is 32 bits wide
    // write a for loop that reads
    // each bit in order from left
    // to right and prints them out

    for(int idx = 31; idx >= 0; idx--) {
        printf("%d", (num >> idx) & 1);
    }
    printf("\n");
}

void flipBit(int* n, int c) {
    // you can flip the c-th bit
    // by taking (1 << c) and taking the ^
    // with the number n

    *n = (*n) ^ (1 << c);
}

int main() {

    int num;
    int choice;

    printf("Enter an integer: ");
    scanf("%d", &num);
    while(1) {
        printf("The number is: %d\n", num);
        // need a function that will
        // print all the bits in an integer
        printBits(num);
        printf("which bit to flip?: ");
        scanf("%d", &choice);
        flipBit(&num, choice);
    }


    return 0;
}
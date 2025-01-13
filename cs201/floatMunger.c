#include <stdio.h>
#include <stdlib.h>

void printBts(int* n) {

    for (int i = 31; i >= 0; i--) {
        printf("%d\n", (*n >> i)&1);
    }

}

void flipBit() {
   *n = (*n) ^ (1 << c);
}

int main() {

    float num;
    int choice;
    enter a float
    scan num
    while(1){
        print the number is
        printBits((int*)&num);
    }

    return 0;
}

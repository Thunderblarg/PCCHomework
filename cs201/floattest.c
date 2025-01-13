#include <stdio.h>
#include <stdlib.h>

int main(){

    double num1 = 0;

    double num2 = 0.001;

    for (int i = 0; i < 10000; i++) {
        num1 = num1 + num2;
    }

    if (num1 == 10.0) {
        printf("yee-caw\n");
    } else {
        printf("whoops!\n");
    }

    printf("num1 is actually %.20f\n", num1);

    return 0;
}
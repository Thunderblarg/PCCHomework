#include <stdio.h>

int main(){
    int a;      // The first number
    int b;      // The second number

    printf("give number: ");
    scanf("%d", &a);    // we put the first number in a
    printf("give more number: ");
    scanf("%d", &b);    // we put the second number in b

    printf("result: %d\n", a + b); // we print a plus b

    return 0;
}
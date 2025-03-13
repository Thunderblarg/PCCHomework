#include <stdio.h>

int main() {
    int a;
    while(getchar() != '\n');
    printf("Enter an integer: ");
    scanf("%d", &a);  // Check if this basic input works
    printf("You entered: %d\n", a);
    return 0;
}
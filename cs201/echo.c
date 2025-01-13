#include <stdio.h>

int main() {
    char msg[50];

    printf("type something plz: ");
    scanf("%s", msg);
    printf("you said: %s\n", msg);

    printf("And msg is actually: %p\n", msg);

    return 0;
}
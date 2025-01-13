#include <stdio.h>
#include <stdlib.h>

int main() {
    char test = -1;

    if (test > 0){
        printf("unsigned\n");
    }else{
        printf("signed\n");
    }

    return 0;
}
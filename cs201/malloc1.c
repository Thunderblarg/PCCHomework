#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};

int main() {
    printf("The size of Point is %lu\n", sizeof(struct Point));

    // malloc instead of new
    struct Point* pointy = malloc(sizeof(struct Point));

    (*pointy).x = 10;
    (*pointy).y = 20;

    printf("The field x is %d and y is %d\n", (*pointy).x, (*pointy).y);

    (*pointy).x = 40;
    (*pointy).y = 50;

    printf("The field x is %d and y is %d\n", (*pointy).x, (*pointy).y);
    //point
    free(pointy);

    pointy = 0;

    return 0;
}
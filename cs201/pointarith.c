#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr1[5] = {0,1,2,3,4};
    double arr2[5] = {0,1,2,3,4};


    // %d base 10 integers
    // %x base 16 integers
    // %o base 0 integers
    // let's look at the width of the pointers
    // and how they behave when they advance the array

    printf("The start of arr1 is: %p\n", arr1);
    printf("The start of arr2 is: %p\n", arr2);

    for (int idx = 1; idx < 5; idx++){
        printf("the %dth element of arr1 is at %p\n", idx, arr1 + idx);
        printf("the %dth element of arr2 is at %p\n", idx, arr2 + idx);
    }

    return 0;
}
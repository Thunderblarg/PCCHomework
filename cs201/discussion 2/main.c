#include <stdio.h>

int main(){
    int number = 0;
    int exit = 0;
    int complement = 0;

    while(!exit){
        number = 0;
        complement = 0;
        printf("Give me an integer so I can say nice things about it: ");
        scanf("%d", &number);
        complement = ~number + 1;

        printf("The binary encoding of your number is: ");
    
        for (int idx = 31; idx >= 0; idx--) {
            printf("%d", (number >> idx) & 1);
        }

        printf("\n");


        printf("Two's complement of the number is: ");
        printf("%d\n", complement);

        printf("If this number was unsigned, it would be: ");
        printf("%u", (unsigned int)complement);
        printf("\n");

        printf("The binary encoding of the complement is: ");
        for (int idx = 31; idx >= 0; idx--) {
            printf("%d", (complement >> idx) & 1);
        }
        
        printf("\nDon't forget, you're here forever!\n");

    }

}
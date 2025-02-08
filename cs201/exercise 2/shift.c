#include <stdio.h>
#include <math.h>

#define FIELD_LENGTH 8
#define EXPONENT_FIELD 3

int main(){
    int n = FIELD_LENGTH; // the bits. the number of bits in the field. the number of bits remaining in the field. the bits.
    int s;
    int ex = 0;
    int ef = EXPONENT_FIELD; // max exponent bits
    int rPolarity;
    int r;
    int k; // turn r into k
    int some_kind_of_m_bit_integer = 0;
    int m = 0;
    double f = 0.0;


    //prompt for input
    printf("THE CHAR, GIVE 'EM THE CHAR: ");
    unsigned char theChar;
    scanf("%c", &theChar);
    
    // DEBUG
    char displayModel = theChar;
    printf("here are our bits:\n");
    for (int idx = 0; idx < n; idx++){
        printf("%d ", (displayModel & 128) ? 1 : 0);
        displayModel = displayModel << 1;
    }
    printf("\n");

    // get the sign bit
    s = (theChar & 128) ? 1 : 0;

    // decrement n every time we increment our bits
    theChar = theChar << 1;
    n--;

    // DEBUG
    printf("Our sign bit is: %d\n", s);

    // Get the regime polarity
   // printf("(theChar & 128) ? 1 : 0: %d\n", (theChar & 128) ? 1 : 0);
    rPolarity = (theChar & 128) ? 1 : 0;
    r = 1;

    // increment our bits
    theChar = theChar << 1;
    n--;

    // DEBUG
    printf("(theChar & 128): %d\n", (theChar & 128) ? 1 : 0);
    printf("(theChar & 128) == rPolarity: %d\n", (theChar & 128 ? 1 : 0) == rPolarity);

    // Start counting our regime bits
    while(((theChar & 128) ? 1 : 0) == rPolarity && n){
        r++;
        theChar = theChar << 1;
        n--;
    }

    printf("The regime polarity is: %d\n", rPolarity);
    
    // DEBUG
    printf("r: %d\n", r);
    printf("n: %d\n\n", n);

    k = rPolarity ? r-1 : r * -1;
    printf("k: %d\n", k);

    // increment our bits after the loop
    theChar = theChar << 1;
    n--;

    
    // Start tallying up our exponent
    while(n && ef){
        // DEBUG
        // printf("(int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0): %d\n", (int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0));

        ex ^= (int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0);
        theChar = theChar << 1;
        n--;
        ef--;
    }                     
    
    // DEBUG
    printf("ex: %d\n", ex);
    printf("n: %d\n\n", n);
    // printf("in loop:\n");
    getchar();

    while(n){
        // DEBUG
        // printf("n: %d\n", n);
        // printf("pow(2, 0): %lf\n", pow(2, 0));
        // printf("pow(2, (n - 1)): %lf\n", (double)pow(2.0, (n - 1)));
        // printf("(double)(1 / pow(2, (n-1))): %lf\n", (double)(1.0 / pow(2.0, (n-1))));
        
        printf("(theChar & 128) ? 1 : 0: %d\n", (theChar & 128) ? 1 : 0);
        printf("adding %d to m\n", ((int)pow(2, n - 1) * ((theChar & 128) ? 1 : 0)));
        
        //   while(n && ef){
        //     // DEBUG
        //     // printf("(int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0): %d\n", (int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0));

        //     ex ^= (int)pow(2, ef - 1) * ((theChar & 128) ? 1 : 0);
        //     theChar = theChar << 1;
        //     n--;
        //     ef--;
        // } 
        printf("some_kind_of_m_bit_integer before: %d\n", some_kind_of_m_bit_integer);
        some_kind_of_m_bit_integer += (int)pow(2, n - 1) * ((theChar & 128) ? 1 : 0);
        printf("some_kind_of_m_bit_integer after: %d\n", some_kind_of_m_bit_integer);
        // m += (double)(1.0 / pow(2, (n))) * ((theChar & 128) ? 1.0 : 0.0);
        theChar = theChar << 1;
        m++;
        n--;
        getchar();
    }


    printf("some_kind_of_m_bit_integer: %d\n", some_kind_of_m_bit_integer);
    f = some_kind_of_m_bit_integer / pow(2, m);

    // DEBUG
    printf("f: %lf\n", f);
    printf("m: %d\n", m);
                                    
    double posit = (double) ((1 - (3 * s)) + f) * pow(2, (1 - (2 * s)) * ((4 * r) + ex + s));

    // double posit = rPolarity ? pow(-1, s) * pow(2, -1 * pow(r, EXPONENT_FIELD)) * pow(2, ex) * (1 + m)
    //                          : pow(-1, s) * pow(2, (r * -1) * pow(2, EXPONENT_FIELD)) * pow(2, ex) * (1 + m);

    printf("if this char was a posit, it would be %.20f\n", posit);

    return 0;
}
/*
1. Understand the basics of while loops
2. Understand how to use logical operators in C
3. Understand DeMorgan's theorem
*** this is INCREDIBLY important when thinking about NEGATING AND(&&) or OR(||) conditions
4. Understand the fencepost technique
 */

#include <stdio.h>

int main(void){
    int x_1 = 5;
    // prints out "Small" 5 times, until the boolean == false
    while (x_1 < 10) {
        printf("Small\n");
        x_1++;
    }

    int i = 6;
    // in this case, the boolean expression is evaluated first before i = i - 1
    while (i-- > 0) {
        if (i == 0) {
            printf("0 here\n");
        }
        printf("%d\n", i);
    }

    int count = 5;
    // this prints count 5 times, contrary to what you would think
    while (count-- > 0) {
        printf("hello\n");
}

}

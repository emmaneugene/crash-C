/* 
Objectives:
1. Understand how to initialise arrays
2. Variable length arrays
3. Gotcha (assignment and comparison)
 */

#include <stdio.h>
#include <stdbool.h>
#define SIZE 4 // we use the #define preprocesor directive to allow constant values to by declared throughout the code

int main(void) {
    // if you don't initialise values in array when declaring, you will get random values from memory

    // if you don't know what values your array should take, you should initialise them all to 0 first

    // you can do it using a for-loop, or individually specify
    // int x[3] = {0, 0, 0}
    // int x[3];
    // for (int i = 0; i < 3; i++) {
    //     x[i] = 0;
    // }

    // this is a code shorthand for you, but it can only be done during compile-time, NOT runtime
    // thus, we cannot do this for a variable length array
    int x[3] = {0};

    // variable length arrays can be used as well, 
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int y[n];
    for (int i = 0; i < n; i++) {
        y[i] = 0;
        printf("%d\n", y[i]);
    }

}
/* 
1. Relationship between arrays and pointers
 - Understand that arrays are simply passed as pointers between function calls
 */

#include <stdio.h>

void print_array(int *values, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", *values++);
    }
}

int main(void) {
    int values[] = {30, 40, 50};
    // Good practice to initialise pointers as null until you need them
    int *ptr = NULL;
    ptr = values;

    // Notice that we can use arithmetic (addition and subtraction to get at any values stored before/after the current pointer)
    // This is similar to indexing in arrays - just like indexing in arrays, we can encounter errors if we go too far
    printf("Indexing forwards...\n");
    printf("%d\n", *ptr++); 
    printf("%d\n", *ptr++);
    printf("%d\n", *ptr);

    printf("Indexing backwards...\n");
    printf("%d\n", *--ptr);

    printf("Indexing out of bounds...\n");
    *(ptr += 3);
    // Take note of the order of operations. Dereferencing comes before arithmetic, so we need to use parentheses
    printf("%d\n", *ptr);

    print_array(values, 3);
}
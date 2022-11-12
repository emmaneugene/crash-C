/* 
Objectives:
1. Learn how to use arrays to represent a list of values (of the same datatype)
2. Declare and initialize an array
3. Use the index operator to refer to an individual element of an array
4. Remember that arrays are zero-indexed
 */

#include <stdio.h>

int main(void){
    // You can choose not to specify the number of elements in an array when declaring it, but this is recommended
    int numbers[3] = {2, 5, 8};

    /* 
    INDEX:   [0] [1] [2]
            +---+---+---+
    VALUE:  | 2 | 5 | 8 |
            +---+---+---+
     */

    // Arrays are mutable; you can change the value of items in an array
    numbers[0] = 4;

    printf ("Indexing through array:\n");
    for (int i = 0; i < 3; i++) {
        printf("Numbers[%d]: %d\n", i, numbers[i]);
    }

    printf("%d\n", numbers[90]);
}
#include <stdio.h>
#include <stdlib.h>

int *store_num_in_array(int num) {
    // Takes in a number, and returns a pointer to an array of integers with those numbers
    // Negative signs will not be accounted for
    int num_copy = num;
    int length = 0;
    while (num_copy != 0) {
        num_copy /= 10;
        length++;
    }

    int *num_array = calloc(length, sizeof(int));

    // Copy number into array
    for (int i = length - 1; i >= 0; i--) {
        num_array[i] = num % 10;
        num /= 10;
    }
    return num_array;
}

int main(void) {
    {
        printf("Test 1:\n");
        int num = 123456;
        int *ptr = store_num_in_array(num);
        for (int i = 0; i < 6; i++) {
            printf("%d\n", ptr[i]);
        }

        free(ptr);
    }
}

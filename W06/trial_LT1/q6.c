/**
 *
 * Name: Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 *
 */

#include <stdio.h>

void print_pascal(int num) {
    // Fully declare the size of the array until you want it to be
    int current_array[num];
    current_array[0] = 1;

    int next_array[num];
    next_array[0] = 1;
    next_array[1] = 1;

    // For each line
    for (int i = 1; i <= num; i++) {
        // Print out everything in current_array[]
        for (int j = 0; j < i; j++) {
            printf("%d ", current_array[j]);
        }

        // Copy over next_array[] to current_array[]
        for (int k = 0; k <= i + 1; k++) {
            current_array[k] = next_array[k];
        }

        // Use current_array[] to get new next_array[]
        for (int l = 0; l < i + 1; l++) {
            if (l != i) {
                next_array[l + 1] = current_array[l] + current_array[l + 1];
            } else {
                next_array[l + 1] = current_array[l];
            }
        }
        printf("\n");
    }
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:\n");
    printf("1 \n");
    printf("1 1\n");
    printf("1 2 1\n");
    printf("1 3 3 1\n");
    printf("1 4 6 4 1\n");
    printf("Actual:\n");
    print_pascal(5);
}

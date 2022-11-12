#include <stdio.h>

#define SIZE_FIVE 5
#define SIZE_ONE 1

void bubble_sort(int values[], int size) {
    int temp;
    // Number of iterations we will go through
    for (int i = 0; i < size - 1; i++) {
        // Comparisons we need to make in each iteration
        for (int j = 0; j < size - 1 - i; j++) {
            if (values[j] > values[j+1]) {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
}

void print_array(int values[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}
int main(void) {
    {
        int values[SIZE_FIVE] = {7, 3, 6, 5, 1};
        bubble_sort(values, SIZE_FIVE);
        printf("Expected:1 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[] = {2, 3, 5, 6, 7};
        bubble_sort(values, SIZE_FIVE);
        printf("Expected:2 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[SIZE_ONE] = {1};
        bubble_sort(values, SIZE_ONE);
        printf("Expected:1\n");
        printf("Actual  :");
        print_array(values, SIZE_ONE);
        printf("\n");
    }
}

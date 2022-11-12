#include <stdio.h>

#define SIZE_FIVE 5
#define SIZE_ONE 1

void selection_sort(int values[], int size) {
    int index_min;
    int temp;
    for (int i = 0; i < size; i++) {
        index_min = i;
        for (int j = i; j < size; j++) {
            if (values[j] < values[index_min]) {
                index_min = j;
            }
        }
        // Swap values[i] with values[index_min]
        temp = values[i];
        values[i] = values[index_min];
        values[index_min] = temp;
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
        selection_sort(values, SIZE_FIVE);
        printf("Expected:1 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[] = {2, 3, 5, 6, 7};
        selection_sort(values, SIZE_FIVE);
        printf("Expected:2 3 5 6 7\n");
        printf("Actual  :");
        print_array(values, SIZE_FIVE);
        printf("\n");
    }

    {
        int values[SIZE_ONE] = {1};
        selection_sort(values, SIZE_ONE);
        printf("Expected:1\n");
        printf("Actual  :");
        print_array(values, SIZE_ONE);
        printf("\n");
    }
}

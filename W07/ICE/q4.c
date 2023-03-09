#include <stdio.h>

#define SIZE_ZERO 0
#define SIZE_THREE 3
#define SIZE_SIX 6
#define SIZE_TEN 10

void bubble_sort(int values[], int size) {
    int temp;
    // Number of iterations we will go through
    for (int i = 0; i < size - 1; i++) {
        // Comparisons we need to make in each iteration
        for (int j = 0; j < size - i - 1; j++) {
            if (values[j] > values[j+1]) {
                temp = values[j+1];
                values[j+1] = values[j];
                values[j] = temp;
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

double get_median(int numbers[], int length) {
    // Corner case
    if (length == 0) {
        return 0;
    }

    bubble_sort(numbers, length);

    double median = (double)numbers[length/2];
    if (length % 2 == 0) {
        median += (double)numbers[length/2 - 1];
        median /= 2;
    }
    return median;
}

int main(void) {
    {
        printf("Test 1\n");
        int values[SIZE_THREE] = {1, 3, 5};
        double result = get_median(values, SIZE_THREE);
        printf("Expected:3\n");
        printf("Actual  :%lf\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int values[SIZE_TEN] = {20, 3, 5, 2, 10, 2, 4, 6, 8, 10};
        double result = get_median(values, SIZE_TEN);
        printf("Expected:5.500000\n");
        printf("Actual  :%lf\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int values[SIZE_SIX] = {20, 4, 2, 10, 2, 4};
        int result = get_median(values, SIZE_SIX);
        printf("Expected:4\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

        {
        printf("Test 4\n");
        int values[SIZE_ZERO] = {};
        int result = get_median(values, SIZE_ZERO);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}

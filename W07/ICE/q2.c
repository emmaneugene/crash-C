#include <stdio.h>

#define SIZE_ZERO 0
#define SIZE_THREE 3
#define SIZE_SIX 6
#define SIZE_TEN 10

int count_odd_numbers(int values[], int size) {
    int sum_odd = 0;

    for (int i = 0; i < size; i++) {
        if (values[i] % 2 == 1) {
            sum_odd++;
        }
    }

    return sum_odd;
}

int main(void) {
    {
        printf("Test 1\n");
        int values[SIZE_THREE] = {1, 3, 5};
        int result = count_odd_numbers(values, SIZE_THREE);
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int values[SIZE_TEN] = {20, 3, 5, 2, 10, 2, 4, 6, 8, 10};
        int result = count_odd_numbers(values, SIZE_TEN);
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int values[SIZE_SIX] = {20, 4, 2, 10, 2, 4};
        int result = count_odd_numbers(values, SIZE_SIX);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

        {
        printf("Test 4\n");
        int values[SIZE_ZERO] = {};
        int result = count_odd_numbers(values, SIZE_ZERO);
        printf("Expected:0\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}

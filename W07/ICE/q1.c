#include <stdio.h>

#define SIZE_THREE 3
#define SIZE_SEVEN 7
#define SIZE_ZERO 0

double average(int values[], int size) {
    double sum = 0;
    // Corner case
    if (size < 1) {
        return sum;
    } 

    for (int i = 0; i < size; i++) {
        sum += values[i];
    }

    return sum / size;
}

int main(void) {
    {
        printf("Test 1\n");
        int values[SIZE_THREE] = {1, 5, 13};
        double result = average(values, SIZE_THREE);
        printf("Expected:6.333333\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int values[SIZE_SEVEN] = {13, 1, 9, 5, 13, 75, 100};
        double result = average(values, SIZE_SEVEN);
        printf("Expected:30.857143\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int values[SIZE_THREE] = {0, 0, 0};
        double result = average(values, SIZE_THREE);
        printf("Expected:0.000000\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int values[SIZE_ZERO] = {};
        double result = average(values, SIZE_ZERO);
        printf("Expected:0.000000\n");
        printf("Actual  :%f\n", result);
        printf("\n");
    }
}

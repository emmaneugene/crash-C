#include <stdio.h>

int count_high_temperatures(double inputs[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (inputs[i] > 37.5) {
            count++;
        }
    }
    return count;
}

int main(void) {
    {
        double inputs[] = {36.9, 37.6, 37.2, 37.1, 38.1};
        int result = count_high_temperatures(inputs, sizeof(inputs) / sizeof(double));
        printf("Test 1\n");
        printf("Expected:2\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
    {
        double inputs[] = {37.9, 38.2, 38.8, 37.5, 37.3, 37.0};
        int result = count_high_temperatures(inputs, sizeof(inputs) / sizeof(double));
        printf("Test 2\n");
        printf("Expected:3\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
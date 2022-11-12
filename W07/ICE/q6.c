/*
  Top-Down Design
  This may be a problem that is too complicated to solve by one function alone.
  1. Try breaking the problem down into sub-problems. Each sub-problem is a helper function.
  2. To identify a sub-problem, start writing the algorithm out. 
  3. When you get to a step that seems too complicated, imagine you have a helper function that can solve that step.
     See if you can write the function by including a call to this imaginary function, 
  4. The process can then be repeated on the helper functions until the solution is complete.
*/
#include <stdio.h>
#include <math.h>

double average(int values[], int len) {
    double sum = 0;
    // Corner case
    if (len < 1) {
        return sum;
    } 

    for (int i = 0; i < len; i++) {
        sum += values[i];
    }

    return sum / len;
}

double calculate_variance(int numbers[], int len) {
    // Corner case
    if (len < 2) {
        return -1;
    }

    // Get average of numbers[]
    double mean = average(numbers, len);

    // Sum up (numbers[i] - average of numbers) ^ 2
    double sum_of_sq_diff = 0;
    for (int i = 0; i < len; i++) {
        sum_of_sq_diff += pow((numbers[i] - mean), 2);
    }
    
    // Divide sum_of_sq_diff by len - 1, and we have our variance
    return sum_of_sq_diff / (len - 1);
}

int main(void) {
    {
        printf("Test 1\n");
        int numbers[] = {17, 15, 23, 7, 9, 13};
        double result = calculate_variance(numbers, 6);
        printf("Expected:33.200000\n");
        printf("Actual  :%lf\n", result);
                printf("\n");

    }

    {
        printf("Test 2\n");
        int numbers[] = {1, 2};
        double result = calculate_variance(numbers, 2);
        printf("Expected:0.500000\n");
        printf("Actual  :%lf\n", result);
        printf("\n");
    }

    {
        // variance requires at least two data points
        // thus returns -1
        printf("Test 3\n");
        int numbers[] = {1};
        double result = calculate_variance(numbers, 1);
        printf("Expected:-1.000000\n");
        printf("Actual  :%lf\n", result);
    }
}

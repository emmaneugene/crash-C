/*
   Name : Emmanuel Oh Eu-Gene
   Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
#include <math.h>

int rearrange_digits(int num, int pivot) {
    // First, check if the digit is negative
    int negative_multiplier = 1;
    if (num < 0) {
        num *= -1;
        negative_multiplier *= -1;
    }

    // Find length of number
    int num_length = 0;
    int num_copy = num;
    while (num_copy > 0) {
        num_length ++;
        num_copy /= 10;
    }
    
    int num_array[num_length];
    
    // Copy the number into an array
    for (int i = num_length - 1; i >= 0; i--) {
        num_array[i] = num % 10;
        num /= 10;
    }
    
    int sum_larger = 0;
    int sum_larger_power = 0;
    int sum_equal = 0;
    int sum_equal_power = 0;
    int sum_lesser = 0;
    int sum_lesser_power = 0;
    

    // Iterate over the array from front to back and add into the respective sums
    for (int j = 0; j < num_length; j++) {
        if (num_array[j] > pivot) {
            sum_larger = sum_larger * 10 + num_array[j];
            sum_larger_power++;
        } else if (num_array[j] == pivot) {
            sum_equal = sum_equal * 10 + num_array[j];
            sum_equal_power++;
        } else {
            sum_lesser = sum_lesser * 10 + num_array[j];
            sum_lesser_power++;
        }
    }

    int rearranged_num = sum_lesser + sum_equal * (int) pow(10, sum_lesser_power) + sum_larger * (int) pow(10, sum_lesser_power + sum_equal_power);
    return rearranged_num * negative_multiplier;
}


int main(void) {
    {
        printf("Test 1\n");
        int result = rearrange_digits(415, 3);
        printf("Expected:451\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 2\n");
        int result = rearrange_digits(123454321, 3);
        printf("Expected:454331221\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 3\n");
        int result = rearrange_digits(61728394, 5);
        printf("Expected:67891234\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 4\n");
        int result = rearrange_digits(61728394, 0);
        printf("Expected:61728394\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 5\n");
        int result = rearrange_digits(6900, 9);
        printf("Expected:9600\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }

    {
        printf("Test 6\n");
        int result = rearrange_digits(-1245, 3);
        printf("Expected:-4512\n");
        printf("Actual  :%d\n", result);
        printf("\n");
    }
}
#include <stdio.h>
#include <stdbool.h>

int swap_digit_pairs(int n){
    int output_digit = 0;
    int multiplier = 1;
    int next_pair;
    int swapped_pair;

    while (n >= 10 || n <= -10) {
        // Get the next pair 
        next_pair = n % 100;
        // Swap the next pair (we don't care if it's a single digit)
        swapped_pair = (next_pair % 10) * 10 + next_pair / 10;
        // Add the output to swapped pair * pow(100, c)
        output_digit += swapped_pair * multiplier;
        // Long divide n by 100
        n /= 100;
        // Multiplier * 100
        multiplier *= 100;
    }
    output_digit += n * multiplier;

    return output_digit;
}

int main(void) {
    {
        printf("Test 1\n");
        int result = swap_digit_pairs(1);
        printf("Expected:1\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 2\n");
        int result = swap_digit_pairs(32);
        printf("Expected:23\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 3\n");
        int result = swap_digit_pairs(90);
        printf("Expected:9\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 4\n");
        int result = swap_digit_pairs(971);
        printf("Expected:917\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 5\n");
        int result = swap_digit_pairs(382818);
        printf("Expected:838281\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 6\n");
        int result = swap_digit_pairs(-13);
        printf("Expected:-31\n");
        printf("Actual  :%d\n\n", result);
    }

    {
        printf("Test 7\n");
        int result = swap_digit_pairs(-1347);
        printf("Expected:-3174\n");
        printf("Actual  :%d\n\n", result);
    }
}
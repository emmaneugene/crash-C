/**
 *
 * Name: Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 *
 */

#include <math.h>
#include <stdio.h>

void print_expanded_form(int num) {
    // Check for invalid input
    if (num <= 0) {
        printf("Invalid Input!\n");
        return;
    }
    // Get the length of the number
    int count = 0;
    int num_copy = num;
    while (num_copy > 0) {
        num_copy /= 10;
        count++;
    }

    int decimal_digits[count];

    // Read decimal digits and pass them into the array from back to front
    for (int i = count - 1; i >= 0; i--) {
        decimal_digits[i] = num % 10;
        num /= 10;
    }

    // Print decimal digits with fenceposting
    printf("%d", decimal_digits[0] * (int)pow(10, count - 1));
    for (int i = 1; i < count; i++) {
        if (decimal_digits[i] > 0) {
            printf(" + %d", decimal_digits[i] * (int)pow(10, count - 1 - i));
        }
    }
    return;
}

int main(void) {
    printf("Test 1\n");
    printf("Expected:");
    printf("10 + 2\n");
    printf("Actual  :");
    print_expanded_form(12);
    printf("\n");

    printf("Test 2\n");
    printf("Expected:");
    printf("100 + 20 + 3\n");
    printf("Actual  :");
    print_expanded_form(123);
    printf("\n");

    printf("Test 3\n");
    printf("Expected:");
    printf("100000 + 4\n");
    printf("Actual  :");
    print_expanded_form(100004);
    printf("\n");

    printf("Test 4\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(0);
    printf("\n");

    printf("Test 5\n");
    printf("Expected:");
    printf("Invalid Input!\n");
    printf("Actual  :");
    print_expanded_form(-163);
    printf("\n");
}

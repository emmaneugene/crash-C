#include <stdio.h>

int main(void) {
    int n;
    printf("Enter positive integer:");
    scanf("%d", &n);

    int sum_of_factors = 0;

    /*
     we don't need to iterate from 1 to n, we actually only need to iterate to n/2 for even numbers.
     for odd numbers, we can still divide by 2 - we'll drop the .5 decimal place 
     this can save computational complexity if we have large numbers
    */
    for (int i = 1; i <= n / 2; i++) { 
        if (n % i == 0) {
            sum_of_factors += i;
        }
    }

    if (sum_of_factors == n) {
        printf("%d is a perfect number\n", n);
    } else {
        printf("%d is not a perfect number\n", n);
    }
}
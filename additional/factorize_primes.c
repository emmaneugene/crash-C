#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 Checks if a number n is prime by trying to divide it by integers from integers
 2 to sqrt(n). If the number is not divisible by any of of those values, it is prime.
*/
bool is_prime(int num){
    if (num == 1) {
        return false;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void factorize_primes(int num) {
    if (num == 1) {
        printf("No prime factors");
        return;
    }

    int divisor = 2;
    int power = 0;
    
    while (divisor <= num) {
        if (is_prime(divisor) && num % divisor == 0) {
            while (num % divisor == 0) {
                num /= divisor;
                power++;
            }
            
            printf("%d^%d", divisor, power);
            power = 0;
            if (num > 1) {
                printf(" * ");
            }
        }
        divisor++;
    }
    printf("\n");

}

int main(void) {
    {
        printf("Test case 1\n");
        printf("Expected: 3^2\n");
        printf("Actual  : ");
        factorize_primes(9);
    }

    {
        printf("\n\nTest case 2\n");
        printf("Expected: 2^1 * 13^1\n");
        printf("Actual  : ");
        factorize_primes(26);
    }

    {
        printf("\n\nTest case 3\n");
        printf("Expected: 2^2 * 3^3\n");
        printf("Actual  : ");
        factorize_primes(108);
    }
    
}

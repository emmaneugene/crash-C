#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num){
    // This function evaluates whether a number is prime
    if (num == 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(void){
    int start;
    printf("Enter start:");
    scanf("%d", &start);

    int end;
    printf("Enter end:");
    scanf("%d", &end);

    // Iterate over all the numbers from start to end
    for (int i = start; i <= end; i++) {
        // Find out whether that number is a prime
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

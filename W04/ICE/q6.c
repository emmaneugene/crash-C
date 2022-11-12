#include <stdio.h>

int main(void){
    int n;
    printf("Enter integer:");
    scanf("%d", &n);

    while (n != -1) {

        // Find the integer value of n backwards
        int n_copy = n;
        int n_backwards = n_copy % 10;
        while (n_copy > 9) {
            n_copy /= 10;
            n_backwards = n_backwards * 10 + n_copy % 10;
        }

        // Check if they match
        if (n == n_backwards) {
            printf("%d is a palindrome.\n\n", n);
        } else {
            printf("%d is not a palindrome.\n\n", n);
        }

        printf("Enter integer:");
        scanf("%d", &n);
    }
    printf("Bye bye!\n");
}
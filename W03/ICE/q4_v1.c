#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int n_fact = 1;

    if (n >= 0) { // user input must be a valid number
        for (int i = 1; i <= n; i ++) {
        n_fact *= i;
        }
        printf("%d! = %d\n", n, n_fact);
    } else {
        printf ("Invalid input.\n");
    }
}

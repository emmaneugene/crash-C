#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int n_fact = 1;

     // User input must be a valid number
    if (n < 0) {
        printf("Invalid input.\n");
        return 0;
    }

    for (int i = 1; i <= n; i ++) {
        n_fact *= i;
    }
    printf("%d! = %d\n", n, n_fact);
}

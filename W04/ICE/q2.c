#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int n_max = n; // Fencepost
    int n_min = n;

    while (n >= 0) {

        if (n > n_max) {
            n_max = n;
        } else if (n < n_min) {
            n_min = n;
        }

        printf("Largest so far == %d. Smallest so far == %d\n", n_max, n_min);

        printf("Enter n:");
        scanf("%d", &n);
    }

    printf("Bye!\n");
}

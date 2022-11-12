#include <stdio.h>

int main(void) { 
    int n; // get user's first input
    printf("Enter n:");
    scanf("%d", &n);

    int n_max = n; // fencepost technique
    int n_min = n;
    printf("Largest so far == %d. Smallest so far == %d", n_max, n_min);

    for (int i = 0; i < 4; i++) {
        printf("\n\nEnter n:");
        scanf("%d", &n);

        //compare each value to the new value of n
        n_max = n_max > n ? n_max : n;
        n_min = n_min < n ? n_min : n;

        printf("Largest so far == %d. Smallest so far == %d", n_max, n_min);
    }
    printf("\n");
}
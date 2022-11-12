#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// code snippet for a random number generator
int main(void) {
    srand(time(0));

    int n;
    printf("Enter upper bound of random number(exclusive): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Random number: %d\n", rand() % n);
    }
}
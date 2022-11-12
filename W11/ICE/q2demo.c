// Author: Dom Cobb
#include <stdio.h>

int compute_sum(n) {
    int sum;
    if (n == 1) { // stopping criterion
        sum = 1;
    } else {
        sum = compute_sum(n - 1) + n;
    }
    return sum;
}

int main(void) {
    printf("%d\n", compute_sum(5));
}

#include <stdio.h>

int main(void){
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    long sum_of_multiples = 0;

    for (int i = 7; i <= n; i += 7) {
        sum_of_multiples += i;
    }

    printf("%ld\n", sum_of_multiples);
}

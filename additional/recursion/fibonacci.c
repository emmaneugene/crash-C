#include <stdio.h>

int fibonacci(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i+ 1));
    }
    printf("\n");
}
#include <stdio.h>

void pick_digit(int n) {
    if (n < 10) {
        printf("%d\n", n);
    } else {
        pick_digit(n / 10);
        printf("%d\n", n % 10);
    }
}

int main(void) {
    {
        printf("Test 1\n");
        printf("Expected:\n");
        printf("1\n");
        printf("3\n");
        printf("9\n");
        printf("7\n");
        printf("4\n");
        printf("8\n");
        printf("Actual  :\n");
        pick_digit(139748);
        printf("\n");
    }

    {
        printf("Test 2\n");
        printf("Expected:\n");
        printf("1\n");
        printf("3\n");
        printf("5\n");
        printf("7\n");
        printf("9\n");
        printf("1\n");
        printf("0\n");
        printf("Actual  :\n");
        pick_digit(1357910);
        printf("\n");
    }

    {
        printf("Test 3\n");
        printf("Expected:\n");
        printf("1\n");
        printf("Actual  :\n");
        pick_digit(1);
        printf("\n");
    }
}

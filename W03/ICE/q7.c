#include <stdio.h>

int main(void) { 
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    // part A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // part B
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");

    // part C
    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    printf("\n");

    // part D
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            printf(" ");
        }
        printf("%c\n", 'A' + i);
    }
    printf("\n");

    // part E
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i || j == (n - 1) - i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
#include <stdio.h>
#include <math.h>
int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    // part A
    for (int i = 0; i < n; i++) {
        printf("--\\|/-");
    }
    printf("\n\n");

    // part B
    for (int i = n; i > 0; i--) {
        printf("%d ", i * i);
    }
    printf("\n\n");

    // part C
    for (int i = 1; i <= n; i++) {
        printf("%d%d%d ", i, i + 1, i + 2);
    }
    printf("\n\n");

    // part D
    for (int i = 0; i < n; i++) {
        printf("%c%c", 'A' + i, 'a' + i);
    }
    printf("\n\n");

    // part E
    int sum = 0;
    for (int i = n; i > 0; i--) {
        sum += i;
        printf("%d ", i);
    }
    printf("(sum: %d)\n\n", sum);

    // part F
    int sum_2 = 0;
    for (int i = 1; i <= n; i++) {
        sum_2 += i * pow(10, i-1); // add 1, 20, 300, 4000, 50000
        printf("%d\n", sum_2);
    }
}

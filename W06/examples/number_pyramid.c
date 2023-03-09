#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int start = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = start; j < start + i; j++) {
            printf("%d ", j);
        }
        start += i;
        printf("\n");
    }
}

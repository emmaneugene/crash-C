#include <stdio.h>

int main(void) {
    int n;
    printf("Enter n:");
    scanf("%d", &n);

    int first = 0;
    int second = 1;
    int next;

    for(int i = 0; i < n; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

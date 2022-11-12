#include <stdio.h>

/* 
Understand how to nest a loop inside another loop
 */

int main(void){
    int n;

    printf("Enter n:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        // this loop determines how many lines will be printed
        for (int j = 1; j <= i; j++) {
            // this loop determines what will be printed on each line
            printf("%d ", j);
        }
        printf("\n");
    }
}
#include <stdio.h>

int main(void) {
    int height;
    printf("Enter the height of the tree, greater than 9:");
    scanf("%d", &height);

    if (height > 9) {
        // print the top of the tree
        for (int i = 0; i < height-5; i++) {
            for (int m = 0; m < height - 5 - i; m++) { // print the whitespace
                printf(" ");
            }
            for (int j = 0; j < 1 + 2 * i ; j++) { // print the asterisks
                printf("*");
            }
            printf("\n");
        }
        // print the bottom
        for (int k = 0; k < 5; k++) {
            for (int l = 0; l < height - 5; l++) {
                printf(" ");
            }
            printf("*\n");
        }
    } else {
        printf("Enter a number greater than 9\n");
    }
}
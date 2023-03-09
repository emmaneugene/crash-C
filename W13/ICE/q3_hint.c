#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int num_rows = 2;
    int num_cols = 3;
    int **two_dim = malloc(num_rows * sizeof(int *));

    for (int i = 0; i < num_rows; i++) {
        two_dim[i] = calloc(num_cols, sizeof(int));
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%d ", two_dim[i][j]);
        }
        printf("\n");
    }

}

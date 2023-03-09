#include <stdio.h>
#include <stdlib.h>

int **matrix_add(int rows, int cols, int matrix_a[rows][cols], int matrix_b[rows][cols]) {
    // Declare new matrix
    int **added_matrix = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        added_matrix[i] = calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            added_matrix[i][j] += matrix_a[i][j] + matrix_b[i][j];
        }
    }

    return added_matrix;
}

void print_array(int m, int n, int **array) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int count = 1;
    {
        int m = 3;
        int n = 3;
        int matrix_a[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int matrix_b[][3] = {{1, 2, 3}, {3, 2, 1}, {2, 1, 3}};
        printf("Test %d\n", count++);
        printf("Expected:\n");
        printf("2 4 6\n");
        printf("7 7 7\n");
        printf("9 9 12\n");
        int **result = matrix_add(m, n, matrix_a, matrix_b);
        printf("Actual:\n");
        print_array(m, n, result);
        printf("\n");
        free(result);
    }

    {
        int m = 3;
        int n = 2;
        int matrix_a[][2] = {{1, 2}, {4, 5}, {7, 8}};
        int matrix_b[][2] = {{1, 2}, {3, 2}, {2, 1}};
        printf("Test %d\n", count++);
        printf("Expected:\n");
        printf("2 4\n");
        printf("7 7\n");
        printf("9 9\n");
        int **result = matrix_add(m, n, matrix_a, matrix_b);
        printf("Actual:\n");
        print_array(m, n, result);
        printf("\n");
        free(result);
    }

    {
        int m = 2;
        int n = 3;
        int matrix_a[][3] = {{1, 2, 1}, {4, 5, 5}};
        int matrix_b[][3] = {{1, 2, 9}, {3, 2, 5}};
        printf("Test %d\n", count++);
        printf("Expected:\n");
        printf("2 4 10\n");
        printf("7 7 10\n");
        int **result = matrix_add(m, n, matrix_a, matrix_b);
        printf("Actual:\n");
        print_array(m, n, result);
        printf("\n");
        free(result);
    }
}

#include <stdbool.h>
#include <stdio.h>

bool valid_nums_present(int values[3][3]) {
    // Create a histogram
    int digits[9] = {0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (values[i][j] > 9 || values[i][j] < 1) {
                return false;
            }
            digits[values[i][j] - 1] = 1;
        }
    }

    // Check if digits 1 to 9 are accounted for
    for (int i = 0; i < 9; i++) {
        if (digits[i] == 0) {
            return false;
        }
    }
    return true;
}

bool is_magic_square(int n, int values[n][n]) {
    if (!valid_nums_present(values)) {
        return false;
    }

    int row_sum = 0;
    int col_sum = 0;
    int diag_sum = 0;

    // Check rows as well as ascending diagonal (i.e. [0][0], [1][1], [2][2])
    for (int i = 0; i < n; i++) {
        row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += values[i][j];
            if (i == j) {
                diag_sum += values[i][j];
            }
        }
        if (row_sum != 15) {
            return false;
        }
    }

    if (diag_sum != 15) {
        return false;
    }

    // Check cols as well as descending diagonal (i.e. [2][0], [1][1], [0][2])
    diag_sum = 0;
    for (int i = 0; i < n; i++) {
        col_sum = 0;
        for (int j = 0; j < n; j++) {
            col_sum += values[j][i];
            if (j == n - 1 - i) {
                diag_sum += values[j][i];
            }
        }
        if (col_sum != 15) {
            return false;
        }
    }

    if (diag_sum != 15) {
        return false;
    }

    return true;
}

int main(void) {
    {
        int values[][3] = {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}};
        printf("Test 1:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};
        printf("Test 2:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}};
        printf("Test 3:%s\n", is_magic_square(3, values) ? "Pass" : "Fail");
        printf("\n");
    }
    {
        int values[][3] = {{5, 5, 5}, {5, 5, 5}, {5, 5, 5}};
        printf("Test 4:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
    {
        int values[][3] = {{2, 6, 7}, {9, 5, 1}, {4, 3, 8}};
        printf("Test 5:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
    {
        int values[][3] = {{10, 4, 1}, {1, 5, 9}, {4, 6, 5}};
        printf("Test 6:%s\n", is_magic_square(3, values) ? "Fail" : "Pass");
        printf("\n");
    }
}

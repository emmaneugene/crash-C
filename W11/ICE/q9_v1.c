#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sieve(int max, int **result, int *n) {
    // Create a list to mark values
    // 0 for unmarked values, 1 if marked
    // e.g. list[2] will tell you if 2 is marked or not, list[3], so on
    int *list = calloc(max + 1, sizeof(int));

    // First prime
    int p = 2;
    // Repeat until p * p is greater than max
    while (p * p <= max) {
        // Cross of all multiples of 2p less or equal to max
        for (int i = 2 * p; i <= max; i += p) {
            list[i] = 1;
        }
        // Find next valid prime
        for (int j = p + 1; j <= max; j++) {
            if (list[j] == 0) {
                p = j;
                break;
            }
        }
    }

    // Count number of unmarked digits
    int count = 0;
    for (int i = 2; i <= max; i++) {
        if (list[i] == 0) {
            count++;
        }
    }
    *n = count;

    // Copy
    int ind = 0;
    *result = malloc(count * sizeof(int));
    for (int i = 2; i <= max; i++) {
        if (list[i] == 0) {
            (*result)[ind++] = i;
        }
    }

    free(list);
}

int main(void) {
    {
        int *result = NULL;
        int n = 0;
        sieve(30, &result, &n);
        printf("Expected:2 3 5 7 11 13 17 19 23 29\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    {
        int *result = NULL;
        int n = 0;
        sieve(100, &result, &n);
        printf("Sieve 100\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }

    {
        int *result = NULL;
        int n = 0;
        sieve(200, &result, &n);
        printf("Sieve 200\n");
        printf("Actual  :");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
    }
}
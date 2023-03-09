/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

/*
    model answer
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

double get_max_score(int W, int n, double wt[n], double val[n]) {
    int i, w;
    double K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - (int)wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int test_id = 0;

    {
        double insta_score[3] = {100, 20, 30};
        double price[3] = {0, 10, 30};
        int n = 3;
        double result = 0;
        int budget = 30;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);

        clock_t begin = clock();
        result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Expected:   130.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }

    {
        double insta_score[3] = {14, 15, 16};
        double price[3] = {10, 15, 15};
        int n = 3;
        double result = 0;
        int budget = 30;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);

        clock_t begin = clock();
        result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Expected:   31.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }

    {
        double insta_score[4] = {2, 6, 3, 1};
        double price[4] = {1, 2, 4, 5};
        int n = 4;
        int budget = 20;
        clock_t begin = clock();

        double result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected:   12.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }

    {
        double insta_score[10] = {2, 6, 3, 1, 2, 3, 4, 5, 6, 17};
        double price[10] = {1, 2, 4, 5, 6, 4, 4, 3, 9, 10};
        int n = 10;
        int budget = 20;
        clock_t begin = clock();

        double result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("―――――――――― Test %d ――――――――――\n", ++test_id);
        printf("Expected:   34.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }

    {
        double insta_score[100] = {0};
        double price[100] = {0};
        int n = 100;
        for (int i = 0; i < n; i++) {
            insta_score[i] = i;
            price[i] = i;
        }
        double result = 0;
        int budget = 20;

        printf("―――――――――― Test %d ――――――――――\n", ++test_id);

        clock_t begin = clock();
        result = get_max_score(budget, n, price, insta_score);
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("Expected:   20.00\n");
        printf("Actual:     %.2f\n", result);
        printf("Time taken: %fs\n", time_spent);
        printf("\n");
    }


}

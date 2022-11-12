#ifndef __TEST_MODE__
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
#endif


int main() {
    int test_id = 0;
    double score = 0;

    {
        double score_worth   = 1;
        double score_awarded = 0;

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

        if (result == 12) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
    }

    {
        double score_worth   = 1;
        double score_awarded = 0;
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

        if (result == 34) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
    }
    {
        double score_worth   = 1;
        double score_awarded = 0;
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

        if (result == 20) {
            score_awarded = score_worth;
        } else {
            score_awarded = 0;
        }
        score += score_awarded;

        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
    }

    printf("score,%s,5,%.1f", __FILE__, score);
}
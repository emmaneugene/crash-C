/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdio.h>
#include <time.h>

/* 
 Create an list items we want to buy (array of structs)
 Sort all items by order of worth (score/price)
 Iterate through items {
    if item is within budget, get it
 }

 This is not a perfect solution, because you might not be able to maximise your budget if you buy the highest worth potatoes
 */

typedef struct {
    double price;
    double score;
    double worth;
} potato;

void sort(potato to_sort[], int size) {
    potato temp;
    // Bubble sort potatoes by worth
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (to_sort[j].worth < to_sort[j+1].worth) {
                temp = to_sort[j];
                to_sort[j] = to_sort[j+1];
                to_sort[j+1] = temp;
            } else if (to_sort[j].worth == to_sort[j+1].worth && to_sort[j].price < to_sort[j+1].price) {
                // if both potatoes are of the same worth, arrange the one with greater price first
                temp = to_sort[j];
                to_sort[j] = to_sort[j+1];
                to_sort[j+1] = temp;
            }
        }
    }
}

double get_max_score(int budget, int n, double prices[], double insta_scores[]) {
    potato potatoes[n];

    for (int i = 0; i < n; i++) {
        potatoes[i].price = prices[i];
        potatoes[i].score = insta_scores[i];
        // corner case for price = 0 is worth = 0 
        if (prices[i] == 0) {
            potatoes[i].worth = 0;
        } else {
            potatoes[i].worth = insta_scores[i] / prices [i];
        }
    }

    // Sort by worth
    sort(potatoes, n);

    // Purchase potatoes starting from most valuable within budget
    double result = 0;

    for (int i = 0; i < n; i++) {
        if (potatoes[i].price <= budget) {
            result += potatoes[i].score;
            budget -= potatoes[i].price;
        }
    }

    return result;
}


int main() {
    int test_id = 0;

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

    {
        double insta_score[3] = {100, 20, 30};
        double price[100] = {0, 10, 30};
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
        double insta_score[3] = {16, 15, 14};
        double price[3] = {15, 15, 10};
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
}
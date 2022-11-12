/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

/* 
    Create a linked list of possible purchase combinations, instead of an array 
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
    double price;
    double score;
} potato;

typedef struct purchase {
    double sum_score;
    double sum_spent;
    struct purchase *next;
} purchase;

void free_list(purchase *head) {
    purchase *prev;
    while (head != NULL) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

purchase *new_purchase(double score, double price) {
    purchase *new = (purchase *)malloc(sizeof(purchase));
    new->sum_score = score;
    new->sum_spent = price;
    new->next = NULL;
    return new;
}

purchase *get_and_compare_next_list(purchase *head, potato new, int budget, double *result) {
    purchase *next_list = new_purchase(new.score, new.price);
    purchase *ptr = next_list;

    if (ptr->sum_score > *result) {
        *result = ptr->sum_score;
    }

    while (head != NULL) {
        if (head->sum_spent + new.price <= (double)budget) {
            ptr->next = new_purchase(head->sum_score + new.score, head->sum_spent + new.price);
            ptr = ptr->next;
            if (ptr->sum_score > *result) {
                *result = ptr->sum_score;
            }
        }
        head = head->next;
    }

    return next_list;
}

double get_max_score(int budget, int n, double prices[], double insta_scores[]) {
    potato potatoes[n];
    
    // 1st round of list comprehension
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (prices[i] <= (double)budget) {
            potatoes[idx].price = prices[i];
            potatoes[idx].score = insta_scores[i];
            idx++;
        }
    }

    
    if (idx == 0) {
        // No valid potatoes to purchase
        return 0;
    }

    // Create pointer for first item in list
    // Create a tracking pointer which points to the last element in the linked list
    purchase *head = new_purchase(potatoes[0].score, potatoes[0].price);
    purchase *last = head;

    double result = head->sum_score;

    // Loop over remaining potatoes for subsequent purchases
    for (int i = 1; i < idx; i++) {
        // Iterate over previous linked list to form a new linked list
        purchase *next_list = get_and_compare_next_list(head, potatoes[i], budget, &result);
        // Append new linked list to end of previous linked list
        last->next = next_list;
        // Get new last element
        while (last->next != NULL) {
            last = last->next;
        }
    }

    // Free all elements
    free_list(head);

    return result;
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
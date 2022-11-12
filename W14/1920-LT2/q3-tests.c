#ifndef __TEST_MODE__
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char *name;
    struct customer *next_customer;
} customer;

void cut_queue(customer **first_customer, customer *queue_cutter, char *unlucky_queuer_name) {

    customer *c = *first_customer;

    if (strcmp(c->name, unlucky_queuer_name) == 0) {
        queue_cutter->next_customer = c;
        *first_customer = queue_cutter;
        //printf("Went in \n");
        return;
    }

    customer *prev = c;
    c = c->next_customer;
    int i = 10;
    while (c) { 
        // printf("c = %s, prev = %s\n", c->name, prev->name);
        // printf("%d\n", i);
        if (strcmp(c->name, unlucky_queuer_name) == 0) {
            queue_cutter->next_customer = c;
            prev->next_customer = queue_cutter;
        }
        prev = c;
        c = c->next_customer;
    }
}

void print_queue(customer *first_customer) {
    customer *c = first_customer;
    while (c->next_customer) {
        printf("%s -> ", c->name);
        c = c->next_customer;
    }
    printf("%s\n", c->name);
}
#endif

int main(void) {
    int test_id = 0;
    double score = 0;

    {
        double score_worth   = 1;
        double score_awarded = 0;

        customer a = {"Aa", NULL};
        customer b = {"Bb", NULL};
        customer c = {"Cc", NULL};
        customer z = {"Zz", NULL};
        customer *first_customer = &a;

        a.next_customer = &b;
        b.next_customer = &c;

        printf("――――― Test %d ―――――\n", ++test_id);
        printf("Expected: Zz -> Aa -> Bb -> Cc\n");
        cut_queue(&first_customer, &z, "Aa");
        printf("Actual  : ");
        print_queue(first_customer);

        if (z.next_customer == &a && 
            a.next_customer == &b &&
            b.next_customer == &c) {
                score_awarded = score_worth;
            } else {
                score_awarded = 0;
            }
        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
        score += score_awarded;
    }

    {
        double score_worth   = 2;
        double score_awarded = 0;

        customer a = {"Aa", NULL};
        customer b = {"Bb", NULL};
        customer c = {"Cc", NULL};
        customer z = {"Zz", NULL};
        customer *first_customer = &a;

        a.next_customer = &b;
        b.next_customer = &c;

        printf("――――― Test %d ―――――\n", ++test_id);
        printf("Expected: Aa -> Zz -> Bb -> Cc\n");
        cut_queue(&first_customer, &z, "Bb");
        printf("Actual  : ");
        print_queue(first_customer);

        if (a.next_customer == &z && 
            z.next_customer == &b &&
            b.next_customer == &c) {
                score_awarded = score_worth;
            } else {
                score_awarded = 0;
            }
        printf("Score: %.1f/2.0\n", score_awarded);
        printf("\n");
        score += score_awarded;
    }

    {
        double score_worth   = 2;
        double score_awarded = 0;

        customer a = {"Aa", NULL};
        customer b = {"Bb", NULL};
        customer c = {"Cc", NULL};
        customer z = {"Zz", NULL};
        customer *first_customer = &a;

        a.next_customer = &b;
        b.next_customer = &c;

        printf("――――― Test %d ―――――\n", ++test_id);
        printf("Expected: Aa -> Bb -> Zz -> Cc\n");
        cut_queue(&first_customer, &z, "Cc");
        printf("Actual  : ");
        print_queue(first_customer);

        if (a.next_customer == &b && 
            b.next_customer == &z &&
            z.next_customer == &c) {
                score_awarded = score_worth;
            } else {
                score_awarded = 0;
            }
        printf("Score: %.1f/2.0\n", score_awarded);
        printf("\n");
        score += score_awarded;
    }


    if (score != 5) {
        printf("This test is skipped, because one or more of the previous test cases failed.\n");
    } else { 
        // this test case is worth something only if the previous 2 test cases were correct
        double score_worth   = 1;
        double score_awarded = 0;

        customer a = {"Aa", NULL};
        customer b = {"Bb", NULL};
        customer c = {"Cc", NULL};
        customer z = {"Zz", NULL};
        customer *first_customer = &a;

        a.next_customer = &b;
        b.next_customer = &c;

        printf("――――― Test %d ―――――\n", ++test_id);
        printf("Expected: Aa -> Bb -> Cc\n");
        cut_queue(&first_customer, &z, "Nobody");
        printf("Actual  : ");
        print_queue(first_customer);

        if (a.next_customer == &b && 
            b.next_customer == &c) {
                score_awarded = score_worth;
            } else {
                score_awarded = 0;
            }
        printf("Score: %.1f/1.0\n", score_awarded);
        printf("\n");
        score += score_awarded;
    }

    printf("score,%s,3,%.1f", __FILE__, score);
}

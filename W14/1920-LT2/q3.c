/**
 * Name : Emmanuel Oh Eu-Gene
 * Email: emmanueloh.2019@sis.smu.edu.sg
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer {
    char *name;
    struct customer *next_customer;
} customer;

void cut_queue(customer **first_customer, customer *queue_cutter, char *unlucky_queuer_name) {
    // Find pointer for queuer_name
    customer *ptr = *first_customer;
    customer *to_cut = NULL;
    customer *in_front = NULL;

    // Corner case: front of the queue
    if (strcmp(unlucky_queuer_name, ptr->name) == 0) {
        queue_cutter->next_customer = ptr;
        *first_customer = queue_cutter;
        return;
    }

    // Else, search queue
    while (ptr->next_customer != NULL) {
        if (strcmp(unlucky_queuer_name, ptr->next_customer->name) == 0) {
            to_cut = ptr->next_customer;
            in_front = ptr;
        }
        ptr = ptr->next_customer;
    }

    if (to_cut == NULL) {
        return;
    }
    
    // Insert cutter
    in_front->next_customer = queue_cutter;
    queue_cutter->next_customer = to_cut;
}

void print_queue(customer *first_customer) {
    customer *c = first_customer;
    while (c->next_customer) {
        printf("%s -> ", c->name);
        c = c->next_customer;
    }
    printf("%s\n", c->name);
}

int main(void) {
    int test_id = 0;

    {
        customer annie = {"Annie", NULL};
        customer benny = {"Benny", NULL};
        customer cammy = {"Cammy", NULL};
        customer doody = {"Doody", NULL};

        customer *first_customer = &annie;

        annie.next_customer = &benny;
        benny.next_customer = &cammy;
        // test 1
        printf("――――― Test %d ―――――\n", ++test_id);
        printf("queue(before):");
        print_queue(first_customer);
        printf("queue(after ):");
        cut_queue(&first_customer, &doody, "Annie");
        print_queue(first_customer);
        printf("\n");
    }

    {
        customer annie = {"Annie", NULL};
        customer benny = {"Benny", NULL};
        customer cammy = {"Cammy", NULL};
        customer doody = {"Doody", NULL};

        customer *first_customer = &annie;

        annie.next_customer = &benny;
        benny.next_customer = &cammy;
        // test 2
        printf("――――― Test %d ―――――\n", ++test_id);

        printf("queue(before):");
        print_queue(first_customer);
        printf("queue(after ):");
        cut_queue(&first_customer, &doody, "Benny");
        print_queue(first_customer);
        printf("\n");
    }

    {
        customer annie = {"Annie", NULL};
        customer benny = {"Benny", NULL};
        customer cammy = {"Cammy", NULL};
        customer doody = {"Doody", NULL};

        customer *first_customer = &annie;

        annie.next_customer = &benny;
        benny.next_customer = &cammy;
        // test 3
        printf("――――― Test %d ―――――\n", ++test_id);

        printf("queue(before):");
        print_queue(first_customer);
        printf("queue(after ):");
        cut_queue(&first_customer, &doody, "Cammy");
        print_queue(first_customer);
        printf("\n");
    }

    {
        customer annie = {"Annie", NULL};
        customer benny = {"Benny", NULL};
        customer cammy = {"Cammy", NULL};
        customer doody = {"Doody", NULL};

        customer *first_customer = &annie;

        annie.next_customer = &benny;
        benny.next_customer = &cammy;
        // test 4
        printf("――――― Test %d ―――――\n", ++test_id);

        printf("queue(before):");
        print_queue(first_customer);
        printf("queue(after ):");
        cut_queue(&first_customer, &doody, "Dante");
        print_queue(first_customer);
        printf("\n");
    }
}

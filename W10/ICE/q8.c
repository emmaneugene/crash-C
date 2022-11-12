#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

int get_middle(node *reading_pointer) {
    // Corner case, if there are no elements
    if (reading_pointer == NULL) {
        return -1;
    }

    // Initialise a middle_pointer
    node* middle_pointer = reading_pointer;
    int tracking_count = 1;
    int assigning_count = 1;

    while (reading_pointer->next != NULL) {
        reading_pointer = reading_pointer ->next;
        tracking_count++;
        
        if (assigning_count !=  tracking_count / 2 + 1) {
            middle_pointer = middle_pointer->next;
            assigning_count++;
        }
    }

    return middle_pointer->value;
}

int main(void) {
    {
        // creates a linked list with 8 nodes
        // 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0
        node *prev = malloc(sizeof(node));
        prev->value = 0;
        prev->next = NULL;

        for (int i = 1; i < 8; i++) {
            node *current = malloc(sizeof(node));
            current->value = i;
            current->next = prev;
            prev = current;
        }

        printf("Test 1\n");
        printf("Expected:3\n");
        printf("Actual  :%d\n", get_middle(prev));
        printf("\n");
    }

    {   
        // 3 -> 7 -> 5
        node last = {5, NULL};
        node second = {7, &last};
        node head = {3, &second};
        printf("Test 2\n");
        printf("Expected:7\n");
        printf("Actual  :%d\n", get_middle(&head));
        printf("\n");
    }

    {
        // 3 -> 2 
        node last = {2, NULL};
        node head = {3, &last};
        printf("Test 3\n");
        printf("Expected:2\n");
        printf("Actual  :%d\n", get_middle(&head));

        printf("\n");
    }

    {
        node head = {3, NULL};
        printf("Test 4\n");
        printf("Expected:3\n");
        printf("Actual  :%d\n", get_middle(&head));

        printf("\n");
    }

    {
        printf("Test 5\n");
        printf("Expected:-1\n");
        printf("Actual  :%d\n", get_middle(NULL));
        printf("\n");
    }
}
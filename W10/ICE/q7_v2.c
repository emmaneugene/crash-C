#include <stdio.h>

typedef struct node {
    int value;
    struct node *next;
} node;

int size(node* start_pointer) {
    // Corner case, if there are no elements
    if (start_pointer == NULL) {
        return 0;
    }

    int count = 0;

    // Go from start_pointer to the next pointer, until start_pointer->next == NULL
    while (start_pointer != NULL) {
        start_pointer = start_pointer->next;
        count++;
    }

    return count;
}

int main(void) {
    {
        node last = {1, NULL};
        node second = {2, &last};
        node head = {3, &second};
        printf("Test 1\n");
        printf("Expected:3\n");
        printf("Actual  :%d\n", size(&head));
        printf("\n");
    }

    {
        node last = {2, NULL};
        node head = {3, &last};
        printf("Test 2\n");
        printf("Expected:2\n");
        printf("Actual  :%d\n", size(&head));
        printf("\n");
    }

    {
        node head = {3, NULL};
        printf("Test 3\n");
        printf("Expected:1\n");
        printf("Actual  :%d\n", size(&head));
        printf("\n");
    }

    {
        printf("Test 4\n");
        printf("Expected:0\n");
        printf("Actual  :%d\n", size(NULL));
        printf("\n");
    }
}

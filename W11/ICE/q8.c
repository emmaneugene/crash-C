#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

void print(node *ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->value);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

node *add(node *ptr, int value) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    if (ptr == NULL) {
        return new;
    }

    node *ptr_copy = ptr;
    while (ptr_copy->next != NULL) {
        ptr_copy = ptr_copy->next;
    }

    ptr_copy->next = new;
    return ptr;
}

int size(node *ptr) {
    int count = 0;
    while (ptr != NULL) {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void free_linked_list(node *ptr) {
    node *prev;
    while (ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
}

int main(void) {
    {
        node *head = NULL;
        head = add(head, 3);
        add(head, 4);
        add(head, 5);
        printf("Expected:3 -> 4 -> 5 -> NULL\n");
        printf("Actual  :");
        print(head);
        printf("Expected(size):3\n");
        printf("Actual  (size):%d\n", size(head));
        free_linked_list(head); // no test for free_linked_list
    }
}

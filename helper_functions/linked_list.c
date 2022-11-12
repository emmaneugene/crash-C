#include <stdio.h>
#include <stdlib.h>

// boilerplate for a linked list

// define a linked list
typedef struct node {
    // insert your data here (doesn't have to be an int)
    int value;
    struct node *next;
} node;

// add a new node to the end
node *addend(node *ptr, int value) {
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

// inserts according to order
node *insert(node *ptr, int value) {
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;

    // Corner case: empty list or first element
    if (ptr == NULL || new->value < ptr->value) {
        new->next = ptr;
        return new;
    }

    node* p1 = ptr;
    node* p2 = p1->next;

    while (p2 != NULL && new->value > p2->value) {
        p1 = p2;
        p2 = p2->next;
    }

    // Insert new between p1 and p2
    p1->next = new;
    new->next = p2;

    return ptr;
}

// find value and return pointer to that item
node *find(node *ptr, int to_find) {
    // linear search
    while (ptr->value != to_find && ptr != NULL) {
        ptr = ptr->next;
    }

    return ptr;
}

void print_list(node *ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }

    printf("\n");
}

// free 
void free_linked_list(node *ptr) {
    node *prev;
    while (ptr != NULL) {
        prev = ptr;
        ptr = ptr->next;
        free(prev);
    }
}

int main(void) {

    node *mylist = NULL;

    mylist = insert(mylist, 4);
    print_list(mylist);

    mylist = insert(mylist, 8);
    print_list(mylist);

    mylist = insert(mylist, 6);
    print_list(mylist);

    mylist = insert(mylist, 1);
    print_list(mylist);
}
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int size;
} stack;

stack *new_stack(int capacity);

int size(stack *ptr);

bool is_empty(stack *ptr);

void push(stack *ptr, int value);

int pop(stack *ptr);

void free_stack(stack *ptr);

int main(void) {
    stack *stk = new_stack(3);

    printf("Is empty?: %s\n", is_empty(stk) ? "true" : "false");

    for (int i = 0; i < 5; i++) {
        push(stk, i * i);
        printf("Capacity: %d\n", stk->capacity);
    }

    printf("Is empty?: %s\n", is_empty(stk) ? "true" : "false");
    printf("Size: %d\n", size(stk));

    while (!is_empty(stk)) {
        printf("Popped: %d\n", pop(stk));
    }

    free_stack(stk);
}

stack *new_stack(int capacity) {
    stack *new_stack = malloc(sizeof(stack));
    new_stack->data = calloc(capacity, sizeof(int));
    new_stack->capacity = capacity;
    new_stack->size = 0;
    return new_stack;
}

int size(stack *ptr) {
    return ptr->size;
}

bool is_empty(stack *ptr) {
    return ptr->size == 0;
}

void push(stack *ptr, int value) {
    if (ptr->size == ptr->capacity) {
        ptr->data = realloc(ptr->data, (ptr->capacity * 3 + 1)/ 2 * sizeof(int));
        ptr->capacity = (ptr->capacity * 3 + 1) / 2;
    }

    (ptr->data)[ptr->size] = value;
    (ptr->size)++;
}

int pop(stack *ptr) {
    (ptr->size)--;
    return (ptr->data)[ptr->size];
}

void free_stack(stack *ptr) {
    free(ptr->data);
    free(ptr);
}

/**
 * Implement a simple stack
 */
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "pile.h"

struct stack_element {
    struct stack_element* next;
    void* element;
};


/**
 * Each stack creation should be followed by a destroy stack to prevent
 * memory lead
 */
struct stack* create_stack(const char* stack_name) {
    int len_name = strlen(stack_name);
    struct stack* stack = (struct stack*) calloc(
        1,
        sizeof(struct stack)
    );

    stack->name = (char *) calloc(len_name+1, sizeof(char));
    strncpy(stack->name, stack_name, len_name);

    return stack;
}

/**
 * Clean memory
 */
void destroy_stack(struct stack* stack) {
    empty(stack);
    free(stack->name);
    free(stack);
}

/**
 * Return 1 if the stack is not empty, 0 otherwise
 */
int not_empty(const struct stack *stack) {
    return stack->first == NULL ? 0 : 1;
}

/**
 * Return the last element on the stack.
 * If the stack is empty, stop the program, the above calling layer must
 * control the stack before poping
 */
void* pop(struct stack *stack) {
    if (!not_empty(stack)) {
        fprintf(stderr, "pop empty stack %s. general error", stack->name);
        exit(1);
    }
    struct stack_element* last = stack->first;
    void* element = last->element;
    stack->first = last->next;
    free(last);
    return element;
}


void push(struct stack *stack, void* element) {
    struct stack_element* new_elt = (struct stack_element*) calloc(
        1,
        sizeof(struct stack_element)
    );
    new_elt->next = stack->first;
    new_elt->element = element;
    stack->first = new_elt;
}

void empty(struct stack *stack) {
    while (not_empty(stack)) {
        pop(stack);
    }
}

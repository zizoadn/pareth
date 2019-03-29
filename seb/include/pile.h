#ifndef _PILE
#define _PILE

/**
 * Implement a simple stack
 */

struct stack {
    char* name; /* This is a good practice to name object to log clear things */
    void* first;
};


/**
 * Initialize stack
 */
struct stack* create_stack(const char*);

/**
 * Destroy the stack and free memory
 */
void destroy_stack(struct stack*);

/**
 * Return 1 if there is still at least one element in the stack, 0 in otherwise
 */
int not_empty(const struct stack*);

/**
 * Return the last element of the stack
 */
void* pop(struct stack*);

/**
 * Add an element on the stack
 */
void push(struct stack*, void*);

/**
 * Empty the stack
 */
void empty(struct stack*);

#endif
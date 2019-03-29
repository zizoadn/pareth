#include <stdio.h>
#include <stdlib.h>

#include "pile.h"

int main() {
    struct stack* stack = create_stack();
    int i = 1;
    int j = 2;
    int k = 3;

    printf("Is empty: %d\n", !not_empty(stack));
    push(stack, &i);
    push(stack, &j);
    printf("2 expected: %d\n", *((int*) pop(stack)));
    printf("Is empty: %d\n", !not_empty(stack));
    push(stack, &k);
    printf("3 expected: %d\n", *((int*) pop(stack)));
    printf("1 expected: %d\n", *((int*) pop(stack)));
    printf("Is empty: %d\n", !not_empty(stack));

    return EXIT_SUCCESS;
}

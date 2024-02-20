#include "stack.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_stack(int size) {
    int i;
    TYPE val;
    struct DList stack;

    printf("\n---------------------------- Testing stack ----------------------------\n");

    /* Create a stack */
    initStack(&stack);

    /* Add elements to the stack */
    for (i = 0; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        pushStack(&stack, val);
    }

    printf("Initial stack:\n");
    print_dlist(&stack);


    val = (TYPE) rand() % RAND_UPPER_BOUND;
    pushStack(&stack, val);
    printf("\nPushed onto stack: \n");
    print_dlist(&stack);


    popStack(&stack);
    printf("\nStack after popping: \n");
    print_dlist(&stack);


    for (i = 1; i < size; i++)
        popStack(&stack);
    printf("\nStack after popping everything: \n");
    print_dlist(&stack);


    /* Test edge case: pop more times than there are elements */
    popStack(&stack);
    printf("\nPopped from empty stack: \n");
    print_dlist(&stack);


    /* Make sure pushing still works */
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    pushStack(&stack, val);
    printf("\nPushed onto stack again: \n");
    print_dlist(&stack);

    freeStack(&stack);
}
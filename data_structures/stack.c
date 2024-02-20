#include "stack.h"

#include <stdlib.h>
#include <assert.h>


void initStack(struct DList *stack) {
    
}


void pushStack(struct DList *stack, TYPE val) {
    
}


void popStack(struct DList *stack) {
    
}


/* Don't have to implement; just for ease of testing */
void freeStack(struct DList *stack) {
    struct DLink *link, *old_link;

    assert(stack != NULL);

    link = stack->frontSentinel;

    do {
        old_link = link;
        link = link->next;
        free(old_link);
    } while(link != stack->backSentinel);

    free(stack->backSentinel);

    stack->frontSentinel = NULL;
    stack->backSentinel = NULL;
}
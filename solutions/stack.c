#include "stack.h"

#include <stdlib.h>
#include <assert.h>


void initStack(struct DList *stack) {
    assert(stack != NULL);

    stack->frontSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(stack->frontSentinel != NULL);

    stack->backSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(stack->backSentinel != NULL);

    stack->frontSentinel->next = stack->backSentinel;
    stack->backSentinel->prev = stack->frontSentinel;
}


void pushStack(struct DList *stack, TYPE val) {
    struct DLink *new_link;

    assert(stack != NULL);

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);

    new_link->value = val;
    new_link->prev = stack->frontSentinel;
    new_link->next = stack->frontSentinel->next;

    new_link->next->prev = new_link;
    stack->frontSentinel->next = new_link;
}


void popStack(struct DList *stack) {
    struct DLink *old_link;

    assert(stack != NULL);

    old_link = stack->frontSentinel->next;

    /* 
     ! Don't forget to check bounds before modifying state
     */
    if(old_link == stack->backSentinel)
        return;

    stack->frontSentinel->next = old_link->next;
    old_link->next->prev = stack->frontSentinel;

    free(old_link);
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
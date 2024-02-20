#include "deque.h"

#include <stdlib.h>
#include <assert.h>


void initDeque(struct DList *dq) {
    assert(dq != NULL);

    dq->frontSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(dq->frontSentinel != NULL);
    dq->backSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(dq->frontSentinel != NULL);

    dq->frontSentinel->next = dq->backSentinel;
    dq->backSentinel->prev = dq->frontSentinel;
}


void addFrontDeque(struct DList *dq, TYPE val) {
    struct DLink *new_link;

    assert(dq != NULL);

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);

    new_link->value = val;
    new_link->next = dq->frontSentinel->next;
    new_link->prev = dq->frontSentinel;

    new_link->next->prev = new_link;
    dq->frontSentinel->next = new_link;
}


void addBackDeque(struct DList *dq, TYPE val) {
    struct DLink *new_link;

    assert(dq != NULL);

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);

    new_link->value = val;
    new_link->next = dq->backSentinel;
    new_link->prev = dq->backSentinel->prev;

    new_link->prev->next = new_link;
    dq->backSentinel->prev = new_link;
}


void removeFrontDeque(struct DList *dq) {
    struct DLink *old_link;

    assert(dq != NULL);

    old_link = dq->frontSentinel->next;

    if(old_link == dq->backSentinel)
        return;

    dq->frontSentinel->next = old_link->next;
    old_link->next->prev = dq->frontSentinel;

    free(old_link);
}


void removeBackDeque(struct DList *dq) {
    struct DLink *old_link;

    assert(dq != NULL);

    old_link = dq->backSentinel->prev;

    if(old_link == dq->frontSentinel)
        return;
    
    dq->backSentinel->prev = old_link->prev;
    old_link->prev->next = dq->backSentinel;

    free(old_link);
}


/* Don't have to implement; just for ease of testing */
void freeDeque(struct DList *dq) {
    struct DLink *link, *old_link;

    assert(dq != NULL);

    link = dq->frontSentinel;

    do {
        old_link = link;
        link = link->next;
        free(old_link);
    } while(link != dq->backSentinel);

    free(dq->backSentinel);

    dq->frontSentinel = NULL;
    dq->backSentinel = NULL;
}
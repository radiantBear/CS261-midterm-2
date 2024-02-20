#include "deque.h"

#include <stdlib.h>
#include <assert.h>


void initDeque(struct DList *dq) {
    
}


void addFrontDeque(struct DList *dq, TYPE val) {
    
}


void addBackDeque(struct DList *dq, TYPE val) {
    
}


void removeFrontDeque(struct DList *dq) {
    
}


void removeBackDeque(struct DList *dq) {
    
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
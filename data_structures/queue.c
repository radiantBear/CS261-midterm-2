#include "queue.h"

#include <stdlib.h>
#include <assert.h>


void initQueue(struct DList *queue) {
    
}


void addQueue(struct DList *queue, TYPE val) {
    
}


void removeQueue(struct DList *queue) {
    
}


/* Don't have to implement; just for ease of testing */
void freeQueue(struct DList *queue) {
    struct DLink *link, *old_link;

    assert(queue != NULL);

    link = queue->frontSentinel;

    do {
        old_link = link;
        link = link->next;
        free(old_link);
    } while(link != queue->backSentinel);

    free(queue->backSentinel);

    queue->frontSentinel = NULL;
    queue->backSentinel = NULL;
}
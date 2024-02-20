#include "queue.h"

#include <stdlib.h>
#include <assert.h>


void initQueue(struct DList *queue) {
    assert(queue != NULL);

    queue->frontSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(queue->frontSentinel != NULL);
    queue->backSentinel = (struct DLink*) malloc(sizeof(struct DLink));

    queue->frontSentinel->next = queue->backSentinel;
    queue->backSentinel->prev = queue->frontSentinel;

}


void addQueue(struct DList *queue, TYPE val) {
    struct DLink *new_link;

    assert(queue != NULL);

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);

    new_link->value = val;
    new_link->next = queue->backSentinel;
    new_link->prev = queue->backSentinel->prev;

    new_link->prev->next = new_link;
    queue->backSentinel->prev = new_link;
}


void removeQueue(struct DList *queue) {
    struct DLink *old_link;

    assert(queue != NULL);

    old_link = queue->frontSentinel->next;

    /* 
     ! Don't forget to check boundary
     */
    if(old_link == queue->backSentinel)
        return;

    queue->frontSentinel->next = old_link->next;
    old_link->next->prev = queue->frontSentinel;

    free(old_link);
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
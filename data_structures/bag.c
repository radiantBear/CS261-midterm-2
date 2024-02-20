#include "bag.h"

#include <stdlib.h>
#include <assert.h>


void initBag(struct DList *bag) {
    
}


void addBag(struct DList *bag, TYPE val) {
    
}


void removeBag(struct DList *bag, TYPE val) {
    
}


void removeAllBag(struct DList *bag, TYPE val) {
    
}


int containsBag(struct DList *bag, TYPE val) {
    
}


struct DLink* _containsBag(struct DList *bag, TYPE val) {
    
}


/* Don't have to implement; just for ease of testing */
void freeBag(struct DList *bag) {
    struct DLink *link, *old_link;

    assert(bag != NULL);

    link = bag->frontSentinel;

    do {
        old_link = link;
        link = link->next;
        free(old_link);
    } while(link != bag->backSentinel);

    free(bag->backSentinel);

    bag->frontSentinel = NULL;
    bag->backSentinel = NULL;
}
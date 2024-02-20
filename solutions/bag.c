#include "bag.h"

#include <stdlib.h>
#include <assert.h>


void initBag(struct DList *bag) {
    assert(bag != NULL);

    bag->frontSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    bag->backSentinel = (struct DLink*) malloc(sizeof(struct DLink));

    bag->frontSentinel->next = bag->backSentinel;
    bag->backSentinel->prev = bag->frontSentinel;
}


void addBag(struct DList *bag, TYPE val) {
    struct DLink *new_link;

    assert(bag != NULL);

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);

    new_link->value = val;
    new_link->next = bag->frontSentinel->next;
    new_link->prev = bag->frontSentinel;

    new_link->next->prev = new_link;
    bag->frontSentinel->next = new_link;
}


void removeBag(struct DList *bag, TYPE val) {
    struct DLink *link;

    assert(bag != NULL);

    link = bag->frontSentinel->next;

    while(link != bag->backSentinel) {
        if(EQ(link->value, val)) {
            link->prev->next = link->next;
            link->next->prev = link->prev;
            free(link);
            return;
        }
        link = link->next;
    }
}


void removeAllBag(struct DList *bag, TYPE val) {
    struct DLink *old_link, *link;

    assert(bag != NULL);

    link = bag->frontSentinel->next;

    while(link != bag->backSentinel) {
        if(EQ(link->value, val)) {
            link->prev->next = link->next;
            link->next->prev = link->prev;
            
            old_link = link;
            link = link->prev;
            
            free(old_link);
        }
        link = link->next;
    }
}


int containsBag(struct DList *bag, TYPE val) {
    assert(bag != NULL);

    if(_containsBag(bag, val) != NULL)
        return 1;

    return 0;
}


struct DLink* _containsBag(struct DList *bag, TYPE val) {
    struct DLink *link;

    assert(bag != NULL);

    link = bag->frontSentinel->next;

    while(link != bag->backSentinel) {
        if(EQ(link->value, val)) {
            return link;
        }
        link = link->next;
    }

    return NULL;
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
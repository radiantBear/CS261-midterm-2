#include "d_linked_list.h"

#include <stdlib.h>
#include <assert.h>


/*
 ? Should create a new link with `value` = `val` and place it before `lnk` 
 */
void addDLink(struct DList *dl, struct DLink *lnk, TYPE val) {
    struct DLink *new_link;

    assert(dl != NULL);

    /* 
     * Shouldn't allow insertion before frontSentinel, but doesn't necessarily need to be 
     * fatal error
     */
    if(lnk == dl->frontSentinel)
        return;

    new_link = (struct DLink*) malloc(sizeof(struct DLink));
    assert(new_link != NULL);
    
    new_link->value = val;
    new_link->next = lnk;
    new_link->prev = lnk->prev;

    lnk->prev->next = new_link;
    lnk->prev = new_link;
}


/* 
 ? Should delete `lnk` and splice the list around it
 */
void removeDLink(struct DList *dl, struct DLink *lnk) {
    assert(dl != NULL);

    /* 
     * Shouldn't allow deletion of sentinels, but doesn't necessarily need to be runtime 
     * error
     */
    if(lnk == dl->frontSentinel || lnk == dl->backSentinel)
        return;
    
    lnk->prev->next = lnk->next;
    lnk->next->prev = lnk->prev;

    free(lnk);
}


void freeEntireDList(struct DList *dl) {
    struct DLink *link, *old_link;

    assert(dl != NULL);
    assert(dl->frontSentinel != NULL);
    assert(dl->backSentinel != NULL);

    link = dl->frontSentinel;

    do {
        old_link = link;
        link = link->next;
        free(old_link);
    } while(link != dl->backSentinel);

    free(link);

    dl->frontSentinel = NULL;
    dl->backSentinel = NULL;
}


/* Don't have to implement; just for ease of testing */
void initDList(struct DList *dl) {
    assert(dl != NULL);

    dl->frontSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(dl->frontSentinel != NULL);
    dl->backSentinel = (struct DLink*) malloc(sizeof(struct DLink));
    assert(dl->backSentinel != NULL);

    dl->frontSentinel->next = dl->backSentinel;
    dl->backSentinel->prev = dl->frontSentinel;
}
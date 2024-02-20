#include "d_linked_list.h"

#include <stdlib.h>
#include <assert.h>


/* Should create a new link with `value` = `val` and place it before `lnk` */
void addDLink(struct DList *dl, struct DLink *lnk, TYPE val) {
    
}


/* Should delete `lnk` and splice the list around it */
void removeDLink(struct DList *dl, struct DLink *lnk) {
    
}


void freeEntireDList(struct DList *dl) {
    
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
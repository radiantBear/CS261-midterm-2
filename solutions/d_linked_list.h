#ifndef D_LINKED_LIST_H
#define D_LINKED_LIST_H

#include "../type.h"

void addDLink (struct DList *dl, struct DLink *lnk, TYPE val);
void removeDLink (struct DList *dl, struct DLink *lnk);
void freeEntireDList (struct DList *dl);

/* Don't have to implement; just for ease of testing */
void initDList(struct DList *dl);

#endif
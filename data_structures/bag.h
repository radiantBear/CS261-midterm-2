#ifndef BAG_H
#define BAG_H

#include "../type.h"
#include "d_linked_list.h"

void initBag(struct DList *bag);
void addBag(struct DList *bag, TYPE val);
void removeBag(struct DList *bag, TYPE val);
void removeAllBag(struct DList *bag, TYPE val);
int containsBag(struct DList *bag, TYPE val);
struct DLink* _containsBag(struct DList *bag, TYPE val);

/* Don't have to implement; just for ease of testing */
void freeBag(struct DList *bag);

#endif
#ifndef DEQUE_H
#define DEQUE_H

#include "../type.h"
#include "d_linked_list.h"

void initDeque(struct DList *dq);
void addFrontDeque(struct DList *dq, TYPE val);
void addBackDeque(struct DList *dq, TYPE val);
void removeFrontDeque(struct DList *dq);
void removeBackDeque(struct DList *dq);

/* Don't have to implement; just for ease of testing */
void freeDeque(struct DList *dq);

#endif
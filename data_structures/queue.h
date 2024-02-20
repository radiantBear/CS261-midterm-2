#ifndef QUEUE_H
#define QUEUE_H

#include "../type.h"
#include "d_linked_list.h"

void initQueue(struct DList *queue);
void addQueue(struct DList *queue, TYPE val);
void removeQueue(struct DList *queue);

/* Don't have to implement; just for ease of testing */
void freeQueue(struct DList *queue);

#endif
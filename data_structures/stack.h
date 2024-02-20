#ifndef STACK_H
#define STACK_H

#include "../type.h"
#include "d_linked_list.h"

void initStack(struct DList *stack);
void pushStack(struct DList *stack, TYPE val);
void popStack(struct DList *stack);

/* Don't have to implement; just for ease of testing */
void freeStack(struct DList *stack);

#endif
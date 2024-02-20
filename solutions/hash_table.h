#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../type.h"

#define MAX_LOAD 3

void initHashTable(struct HashTable *ht, int size);
void addHashTable (struct HashTable *ht, struct DataElem elem);
void _resizeTable(struct HashTable *ht);
int containsHashTable(struct HashTable *ht, struct DataElem elem);
void removeHashTable(struct HashTable *ht, struct DataElem elem); 
void removeAllHashTable(struct HashTable *ht, struct DataElem elem);

/* Don't have to implement; just for ease of testing */
void freeHashTable(struct HashTable *ht);

#endif
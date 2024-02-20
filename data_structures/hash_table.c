#include "hash_table.h"

#include <stdlib.h>
#include <assert.h>


void initHashTable(struct HashTable *ht, int size) {
    
}


/* Doesn't have unique keys restriction */
void addHashTable(struct HashTable *ht, struct DataElem elem) {
    
}


void _resizeTable(struct HashTable *ht) {
    
}


int containsHashTable(struct HashTable *ht, struct DataElem elem) {
    
}


/* Should remove a single match for `elem` in the hash table */
void removeHashTable(struct HashTable *ht, struct DataElem elem) {
    
}


/* Should remove all matches for `elem` in the hash table */
void removeAllHashTable(struct HashTable *ht, struct DataElem elem) {
    
}


/* Don't have to implement; just for ease of testing */
void freeHashTable(struct HashTable *ht) {
    struct DataElem *link, *old_link;
    int i;

    assert(ht != NULL);

    for(i = 0; i < ht->tablesize; i++) {
        link = ht->table[i];
        
        while(link != NULL) {
            old_link = link;
            link = link->next;
            free(old_link->key);
            free(old_link);
        }
    }

    free(ht->table);

    ht->table = NULL;
    ht->tablesize = 0;
    ht->count = 0;
}
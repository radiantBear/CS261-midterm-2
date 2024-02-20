#include "hash_table.h"

#include <stdlib.h>
#include <assert.h>


void initHashTable(struct HashTable *ht, int size) {
    int i;

    assert(ht != NULL);

    ht->table = (struct DataElem**) malloc(sizeof(struct DataElem*) * size);
    assert(ht->table != NULL);

    for(i = 0; i < size; i++)
        ht->table[i] = NULL;
    
    ht->count = 0;
    ht->tablesize = size;
}


void addHashTable(struct HashTable *ht, struct DataElem elem) {
    int index;
    struct DataElem *new_link;

    assert(ht != NULL);

    index = abs(KEY_HASH(elem.key)) % ht->tablesize;

    new_link = (struct DataElem*) malloc(sizeof(struct DataElem));
    assert(new_link != NULL);

    new_link->val = elem.val;
    KEY_COPY(new_link->key, elem.key);
    new_link->next = ht->table[index];

    ht->table[index] = new_link;

    ht->count++;

    if(ht->count / ht->tablesize > MAX_LOAD)
        _resizeTable(ht);
}


void _resizeTable(struct HashTable *ht) {
    struct DataElem **new_table;
    struct DataElem *cur_link, *link;
    int i, new_index, new_size;

    assert(ht != NULL);
    
    new_size = ht->tablesize * 2;
    new_table = (struct DataElem**) malloc(sizeof(struct DataElem*) * new_size);
    assert(new_table != NULL);
    for(i = 0; i < new_size; i++)
        new_table[i] = NULL;

    for(i = 0; i < ht->tablesize; i++) {
        link = ht->table[i];

        while(link != NULL) {
            new_index = abs(KEY_HASH(link->key)) % new_size;
            
            cur_link = link;
            link = link->next;

            cur_link->next = new_table[new_index];
            new_table[new_index] = cur_link;
        }
    }

    free(ht->table);
    ht->table = new_table;
    ht->tablesize = new_size;
}


int containsHashTable(struct HashTable *ht, struct DataElem elem) {
    struct DataElem *link;
    int index;

    assert(ht != NULL);
    
    index = abs(KEY_HASH(elem.key)) % ht->tablesize;

    link = ht->table[index];

    while(link != NULL) {
        if(KEY_EQ(link->key, elem.key))
            return 1;
        
        link = link->next;
    }

    return 0;
}


void removeHashTable(struct HashTable *ht, struct DataElem elem) {
    struct DataElem *link, *prev_link;
    int index;
    
    assert(ht != NULL);

    index = abs(KEY_HASH(elem.key)) % ht->tablesize;

    link = ht->table[index];
    prev_link = NULL;

    while(link != NULL) {
        if(KEY_EQ(link->key, elem.key)) {
            if(prev_link == NULL) 
                ht->table[index] = link->next;
            else
                prev_link->next = link->next;
            free(link->key);
            free(link);
            ht->count--;
            return;
        }

        prev_link = link;
        link = link->next;
    }
}


void removeAllHashTable(struct HashTable *ht, struct DataElem elem) {
    struct DataElem *link, *prev_link;
    int index;
    
    assert(ht != NULL);

    index = abs(KEY_HASH(elem.key)) % ht->tablesize;

    link = ht->table[index];
    prev_link = NULL;

    while(link != NULL) {
        if(KEY_EQ(link->key, elem.key)) {
            if(prev_link == NULL) 
                ht->table[index] = link->next;
            else
                prev_link->next = link->next;
            free(link->key);
            free(link);
            ht->count--;

            if(prev_link == NULL)
                link = ht->table[index];
            else
                link = prev_link->next;
        } else {
            prev_link = link;
            link = link->next;
        }
    }
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
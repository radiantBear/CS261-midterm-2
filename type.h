#ifndef TYPE_H
#define TYPE_H

#include <string.h>
#include <assert.h>

/* For all structures' value */
#define TYPE            int
#define EQ(a, b)        a == b
#define COPY(a, b)      a = b
#define LT(a, b)        a < b

/* For hash table keys */
#define KEY_TYPE        char*
#define KEY_EQ(a, b)    strcmp(a, b) == 0
#define KEY_COPY(a, b)  a = (KEY_TYPE) malloc(strlen(b) + 1); assert(a != NULL); strcpy(a, b)
#define KEY_HASH(a)     string_hash(a)


struct DLink {
    TYPE value;
    struct DLink *prev;
    struct DLink *next;
};

struct DList {
    struct DLink *frontSentinel;
    struct DLink *backSentinel;
};


struct DataElem {
    KEY_TYPE key;
    TYPE val;
    struct DataElem *next;
};

struct HashTable {
    struct DataElem **table;
    int count;                              /* Number of elements in table */
    int tablesize;                          /* Number of buckets/ rows in table */
};


struct Node {
    TYPE val;
    struct Node *left;
    struct Node *right;
};

struct BST {
    struct Node *root;
    int size;
};


unsigned long string_hash(char *str);


#endif
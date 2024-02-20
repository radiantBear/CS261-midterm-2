#include "hash_table.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


const char *KEYS[] = {
    "Alpha",
    "Bravo",
    "Charlie",
    "Delta",
    "Echo",
    "Foxtrot",
    "Golf",
    "Hotel",
    "India",
    "Juliette",
    "Kilo",
    "Lima",
    "Mike",
    "November",
    "Oscar",
    "Papa",
    "Quebec",
    "Romeo",
    "Sierra",
    "Tango",
    "Uniform",
    "Victor",
    "Whiskey",
    "X-ray",
    "Yankee",
    "Zulu"
};


void generate_rand_elmt(struct DataElem *elmt);


void test_hash_table(int size) {
    int i;
    struct DataElem val, remove_val;
    struct HashTable hash_table;

    printf("\n------------------------- Testing hash table --------------------------\n");

    /* Create a hash table */
    initHashTable(&hash_table, 5);

    /* Add elements to the hash table */
    for (i = 0; i < size; i++) {
        generate_rand_elmt(&val);
        addHashTable(&hash_table, val);
        free(val.key);
    }

    printf("\nInitial hash table:\n");
    print_hash_table(&hash_table);


    printf("\n");
    /* Test `contains()` for all possible keys */
    for(i = 0; i < (sizeof(KEYS) / sizeof(KEYS[0])); i += 2) {
        KEY_COPY(val.key, KEYS[i]);
        printf("Hash table contains %s: %s\n", val.key, containsHashTable(&hash_table, val) ? "true" : "false");
        free(val.key);
    }

    
    /* Find an element to remove, if there are any */
    if(size > 0) {
        for(i = 0; i < hash_table.tablesize; i++)
            if(hash_table.table[i] != NULL) {
                /* Have to make copy for repeated use */
                remove_val.next = NULL;
                remove_val.val = hash_table.table[i]->val;
                KEY_COPY(remove_val.key, hash_table.table[i]->key);
                break;
            }

        printf("\nRemoving first element with key %s:\n", remove_val.key);
        removeHashTable(&hash_table, remove_val);
        print_hash_table(&hash_table);

        printf("\nRemoving all elements with key %s:\n", remove_val.key);
        removeAllHashTable(&hash_table, remove_val);
        print_hash_table(&hash_table);


        /* Test edge case: remove element not in hash table */

        printf("\nRemoving an element with value not in hash table:\n");
        removeHashTable(&hash_table, remove_val);
        print_hash_table(&hash_table);

        printf("\nRemoving all elements with value not in hash table:\n");
        removeAllHashTable(&hash_table, remove_val);
        print_hash_table(&hash_table);

        free(remove_val.key);
    }


    printf("\nRemoving all values from hash table:\n");
    for(i = 0; i < (sizeof(KEYS) / sizeof(KEYS[0])); i++) {
        KEY_COPY(val.key, KEYS[i]);
        removeAllHashTable(&hash_table, val);
        free(val.key);
    }
    print_hash_table(&hash_table);

    /* Test edge case: remove element from empty hash table */
    printf("\nRemoving a value from an empty hash table:\n");
    generate_rand_elmt(&val);
    removeHashTable(&hash_table, val);
    free(val.key);
    print_hash_table(&hash_table);
    

    /* Make sure adding still works */
    generate_rand_elmt(&val);
    addHashTable(&hash_table, val);
    free(val.key);
    printf("\nAdded to hash table again: \n");
    print_hash_table(&hash_table);

    freeHashTable(&hash_table);
}


void generate_rand_elmt(struct DataElem *elmt) {
    const char *rand_key;       /* Needed for macro, otherwise rand() will run twice */
    
    rand_key = KEYS[rand() % (sizeof(KEYS) / sizeof(KEYS[0]))];
    KEY_COPY(elmt->key, rand_key);
    elmt->val = (TYPE) rand() % RAND_UPPER_BOUND;
    elmt->next = NULL;
}
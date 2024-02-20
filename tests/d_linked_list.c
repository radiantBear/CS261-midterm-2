#include "d_linked_list.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_d_linked_list(int size) {
    int i, j, idx;
    TYPE val;
    struct DList d_linked_list;
    struct DLink *d_link;

    printf("\n--------------------- Testing doubly-linked list ----------------------\n");

    /* Create a doubly-linked list */
    initDList(&d_linked_list);

    /* Add elements to the doubly-linked list */
    for (i = 0; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;

        /* Find random spot to add the element */
        d_link = d_linked_list.frontSentinel->next;
        idx = rand() % (i + 1);
        for(j = 0; j < idx; j++)
            d_link = d_link->next;
        
        addDLink(&d_linked_list, d_link, val);
    }

    printf("\nInitial doubly-linked list:\n");
    print_dlist(&d_linked_list);
        
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to doubly-linked list front: \n");
    addDLink(&d_linked_list, d_linked_list.frontSentinel->next, val);
    print_dlist(&d_linked_list);
    
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to doubly-linked list back: \n");
    addDLink(&d_linked_list, d_linked_list.backSentinel, val);
    print_dlist(&d_linked_list);


    printf("\nRemoving from doubly-linked list back: \n");
    removeDLink(&d_linked_list, d_linked_list.backSentinel->prev);
    print_dlist(&d_linked_list);

    printf("\nRemoving from doubly-linked list front: \n");
    removeDLink(&d_linked_list, d_linked_list.frontSentinel->next);
    print_dlist(&d_linked_list);
    
    
    printf("\nRemoving everything from doubly-linked list:\n");
    for (i = 0; i < size; i++)
        removeDLink(&d_linked_list, d_linked_list.frontSentinel->next);
    print_dlist(&d_linked_list);


    /* Test edge case: remove frontSentinel */
    printf("\nRemoving front sentinel: \n");
    removeDLink(&d_linked_list, d_linked_list.frontSentinel);
    print_dlist(&d_linked_list);

    /* Test edge case: remove backSentinel */
    printf("\nRemoving back sentinel: \n");
    removeDLink(&d_linked_list, d_linked_list.backSentinel);
    print_dlist(&d_linked_list);


    /* Test edge case: add before frontSentinel */
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding before front sentinel: \n");
    addDLink(&d_linked_list, d_linked_list.frontSentinel, val);
    print_dlist(&d_linked_list);


    /* Ensure adding still works */
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to doubly-linked list: \n");
    addDLink(&d_linked_list, d_linked_list.frontSentinel->next, val);
    print_dlist(&d_linked_list);

    /* Test removal */
    freeEntireDList(&d_linked_list);
    
    /* Edge case: test removal of already-freed list */
    /* Should cause assertion fail, so have to leave commented out */
    /* freeEntireDList(&d_linked_list); */
}
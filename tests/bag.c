#include "bag.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_bag(int size) {
    int i;
    TYPE val, remove_val;
    struct DList bag;

    printf("\n----------------------------- Testing bag -----------------------------\n");

    /* Create a bag */
    initBag(&bag);

    /* Add elements to the bag */
    for (i = 0; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addBag(&bag, val);
    }

    printf("\nInitial bag:\n");
    print_dlist(&bag);

        printf("\n");
        /* For all elements in bag + 1 not in bag */
        for (i = 0; i < RAND_UPPER_BOUND + 1; i++)
            printf("Bag contains %d: %s\n", i, containsBag(&bag, i) ? "true" : "false");

    /* Some tests only make sense if there's elements in the bag */
    if (size > 0) {
        remove_val = bag.frontSentinel->next->value;

        printf("\nRemoving first element by value:\n");
        removeBag(&bag, remove_val);
        print_dlist(&bag);

        printf("\nRemoving all elements with same value:\n");
        removeAllBag(&bag, remove_val);
        print_dlist(&bag);


        /* Test edge case: remove element not in bag */

        printf("\nRemoving an element with value not in bag:\n");
        removeBag(&bag, remove_val);
        print_dlist(&bag);

        printf("\nRemoving all elements with value not in bag:\n");
        removeAllBag(&bag, remove_val);
        print_dlist(&bag);
    }


    printf("\nRemoving all values from bag:\n");
    for(i = 0; i < RAND_UPPER_BOUND; i++) {
        while(containsBag(&bag, i))
            removeBag(&bag, i);
    }
    print_dlist(&bag);


    /* Test edge case: remove element from empty bag */
    printf("\nRemoving a value from an empty bag:\n");
    removeBag(&bag, 0);
    print_dlist(&bag);
    

    /* Make sure adding still works */
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    addBag(&bag, val);
    printf("\nAdded to bag again: \n");
    print_dlist(&bag);

    freeBag(&bag);
}
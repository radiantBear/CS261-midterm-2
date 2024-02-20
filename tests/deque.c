#include "deque.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_deque(int size) {
    int i;
    TYPE val;
    struct DList deque;

    printf("\n---------------------------- Testing deque ----------------------------\n");

    /* Create a deque */
    initDeque(&deque);

    /* Add elements to the deque */
    for(i = 0; i < size / 4; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addFrontDeque(&deque, val);
    }
    /* Add elements to the deque's back */
    for(i = size / 4; i < size / 2; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addBackDeque(&deque, val);
    }
    /* Add more elements to the deque */
    for(i = size / 2; i < 3 * size / 4; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addFrontDeque(&deque, val);
    }
    /* Add more elements to the deque's back */
    for(i = 3 * size / 4; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addBackDeque(&deque, val);
    }

    printf("\nInitial deque:\n");
    print_dlist(&deque);


    /* 
     * Some tests only make sense if there're elements in the deque, otherwise they're  
     * redundant with edge cases below 
     */
    if(size > 0) {
        printf("\nRemoving from deque front: \n");
        removeFrontDeque(&deque);
        print_dlist(&deque);
        
        printf("\nRemoving from deque back: \n");
        removeBackDeque(&deque);
        print_dlist(&deque);
    }
        
        
        printf("\nRemoving everything from deque:\n");
        for (i = 2; i < size; i++)
            removeBackDeque(&deque);
        print_dlist(&deque);


    /* Test edge case: remove from empty deque */

    printf("\nRemoving from empty deque front: \n");
    removeFrontDeque(&deque);
    print_dlist(&deque);
    
    printf("\nRemoving from empty deque back: \n");
    removeBackDeque(&deque);
    print_dlist(&deque);


    /* Ensure adding still works */

    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to deque front: \n");
    addFrontDeque(&deque, val);
    print_dlist(&deque);
    
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to deque back: \n");
    addBackDeque(&deque, val);
    print_dlist(&deque);

    freeDeque(&deque);
}
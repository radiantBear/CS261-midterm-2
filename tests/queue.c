#include "queue.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_queue(int size) {
    int i;
    TYPE val;
    struct DList queue;

    printf("\n---------------------------- Testing queue ----------------------------\n");

    /* Create a queue */
    initQueue(&queue);

    /* Add elements to the queue */
    for (i = 0; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addQueue(&queue, val);
    }

    printf("\nInitial queue:\n");
    print_dlist(&queue);


    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to queue: \n");
    addQueue(&queue, val);
    print_dlist(&queue);


    printf("\nRemoving from queue: \n");
    removeQueue(&queue);
    print_dlist(&queue);
    
    
    printf("\nRemoving everything from queue:\n");
    for (i = 1; i < size; i++)
        removeQueue(&queue);
    print_dlist(&queue);


    /* Test edge case: remove from empty queue */
    printf("\nRemoving from empty queue: \n");
    removeQueue(&queue);
    print_dlist(&queue);


    /* Ensure adding still works */
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to queue: \n");
    addQueue(&queue, val);
    print_dlist(&queue);

    freeQueue(&queue);
}
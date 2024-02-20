#include "data_structures/d_linked_list.h"
#include "data_structures/bag.h"
#include "data_structures/stack.h"
#include "data_structures/queue.h"
#include "data_structures/deque.h"
#include "data_structures/hash_table.h"
#include "data_structures/bst.h"

#include "tests/d_linked_list.h"
#include "tests/bag.h"
#include "tests/stack.h"
#include "tests/queue.h"
#include "tests/deque.h"
#include "tests/hash_table.h"
#include "tests/bst.h"
#include "tests/_helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


/**
 * @brief Tests the implementation of all data structure functions that may appear on the 
 *          second midterm for CS 261 (section 010, Winter 2024). Uses the capacity and 
            size and passed in from the command line to set each data structure's starting
 *          capacity and determine how many elements to add, respectively.
 *
 * @param argc The number of command line arguments
 * @param argv An array of C strings representing the command line arguments
 *
 * @return Returns 0 if execution finishes normally
 */
int main(int argc, char **argv) {
    int size;
    bool proceed;

    proceed = get_input(argc, argv, &size);
    if (!proceed)
        return 0;

    srand((unsigned) time(NULL));

    test_d_linked_list(size);
    test_bag(size);
    test_stack(size);
    test_queue(size);
    test_deque(size);
    test_hash_table(size);
    test_bst(size);

    return 0;
}
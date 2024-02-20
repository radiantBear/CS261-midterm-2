#include "_helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * @brief Tests the implementation of a single data structure that may appear on the 
 *          second midterm for CS 261 (section 010, Winter 2024). Uses the capacity and 
 *          size and passed in from the command line to set each data structure's starting
 *          capacity and determine how many elements to add, respectively. The makefile 
 *          will automatically include the correct headers (eg /tests/bag.h) and define 
 *          the name for the function used to test the structure (eg test_bag).
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

    TEST_FUNCTION(size);    /* Name defined by Makefile */

    return 0;
}
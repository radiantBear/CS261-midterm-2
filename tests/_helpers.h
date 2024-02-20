#ifndef TEST_PRINT_H
#define TEST_PRINT_H

#include "../type.h"
#include <stdbool.h>

#define RAND_UPPER_BOUND 5


/**
 * @brief Prints out all information contained in a doubly-linked list
 */
void print_dlist(struct DList *list);


/**
 * @brief Prints out all information contained in a hash table
 */
void print_hash_table(struct HashTable *table);


/**
 * @brief Prints out all information contained in a binary search tree
 */
void print_bst(struct BST *tree);


/**
 * @brief Gets the command line arguments as an array of integers
 *
 * @param argc  The first argument passed to `main()`:  The number of command line 
 *                  arguments
 * @param argv  The second argument passed to `main()`: An array of C strings representing
 *                  the command line arguments
 * @param size  A pointer to store the value passed from the command line in. Only 
 *                  populated if the arguments are valid (this function returns `true`)
 *
 * @return Whether the command line arguments were valid
 */
bool get_input(int argc, char **argv, int *size);

#endif
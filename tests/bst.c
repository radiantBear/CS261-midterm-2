#include "bst.h"
#include "_helpers.h"
#include <stdio.h>
#include <stdlib.h>


void test_bst(int size) {
    int i;
    TYPE val;
    struct BST tree;

    printf("\n--------------------- Testing binary search tree ----------------------\n");

    /* Create a tree */
    initBST(&tree);

    /* Add elements to the tree */
    for (i = 0; i < size; i++) {
        val = (TYPE) rand() % RAND_UPPER_BOUND;
        addBST(&tree, val);
    }

    printf("\nInitial tree:\n");
    print_bst(&tree);

    printf("\nPreorder tree traversal: ");
    preorderBST(tree.root);
    printf("\nInorder tree traversal: ");
    inorderBST(tree.root);
    printf("\nPostorder tree traversal: ");
    postorderBST(tree.root);
    printf("\nDepth-first tree traversal: ");
    depthFirstBST(&tree);
    printf("\nTop-down tree traversal: ");
    topDownBST(&tree);

    printf("\n\n");
    /* For all elements in bag + 1 not in bag */
    for (i = 0; i < RAND_UPPER_BOUND + 1; i++)
        printf("BST contains %d: %s\n", i, containsBST(&tree, i) ? "true" : "false");

    val = (TYPE) rand() % RAND_UPPER_BOUND;
    printf("\nAdding to tree: \n");
    addBST(&tree, val);
    print_bst(&tree);

    /* For all elements in bag + 1 not in bag */
    printf("\nTesting internal contains function:\n");
    for (i = 0; i < RAND_UPPER_BOUND + 1; i++)
        printf(
            "BST contains %d: %s\n", 
            i, 
            _containsNode(tree.root, i) ? "true" : "false"
        );
        
    printf("\nTesting internal add function:\n");
    val = (TYPE) rand() % RAND_UPPER_BOUND;
    _addNode(tree.root, val);
    tree.size++;                                  /* Have to manually maintain size */
    print_bst(&tree);

    freeBST(&tree);
}
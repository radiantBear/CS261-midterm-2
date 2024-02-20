#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Don't have to implement; just for ease of practicing traversals */
void _processNode(int nodeValue);
/* Don't have to implement; just for ease of testing */
void _freeSubtree(struct Node *node);


void initBST(struct BST *tree) {

}


int containsBST(struct BST *tree, TYPE val) {

}


int _containsNode(struct Node *node, TYPE val) {

}


void addBST(struct BST *tree, TYPE val) {

}


struct Node * _addNode(struct Node *node, TYPE val) {

}


void preorderBST(struct Node *node) {

}


void postorderBST(struct Node *node) {

}


void inorderBST(struct Node *node) {

}


void depthFirstBST(struct BST *tree) {

}


void topDownBST(struct BST *tree) {

}


/* Don't have to implement; just for ease of practicing traversals */
void _processNode(int nodeValue) {
    printf("%d ", nodeValue);
}

/* Don't have to implement; just for ease of testing */
void freeBST(struct BST *tree) {
    assert(tree != NULL);

    _freeSubtree(tree->root);
    tree->size = 0;
    tree->root = NULL;
}

/* Don't have to implement; just for ease of testing */
void _freeSubtree(struct Node *node) {
    if(node == NULL)
        return;

    _freeSubtree(node->left);
    _freeSubtree(node->right);

    free(node);
}
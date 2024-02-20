#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Don't have to implement; just for ease of practicing traversals */
void _processNode(int nodeValue);
/* Don't have to implement; just for ease of testing */
void _freeSubtree(struct Node *node);


void initBST(struct BST *tree) {
    assert(tree != NULL);

    tree->root = NULL;
    tree->size = 0;
}


int containsBST(struct BST *tree, TYPE val) {
    assert(tree != NULL);

    return _containsNode(tree->root, val);
}


int _containsNode(struct Node *node, TYPE val) {
    if(node == NULL)
        return 0;

    if(EQ(val, node->val))
        return 1;
    if(LT(val, node->val))
        return _containsNode(node->left, val);
    return _containsNode(node->right, val);
}


void addBST(struct BST *tree, TYPE val) {
    assert(tree != NULL);

    tree->root = _addNode(tree->root, val);
    tree->size++;
}


struct Node * _addNode(struct Node *node, TYPE val) {
    if(node == NULL) {
        node = (struct Node*) malloc(sizeof(struct Node));
        assert(node != NULL);
        /* 
         ! Don't forget to fill out node's elements
         */
        node->val = val;
        node->left = NULL;
        node->right = NULL;
    } else if(LT(val, node->val)) {
        node->left = _addNode(node->left, val);
    } else {
        node->right = _addNode(node->right, val);
    }

    return node;
}


void preorderBST(struct Node *node) {
    if(node == NULL)
        return;

    _processNode(node->val);
    preorderBST(node->left);
    preorderBST(node->right);
}


void postorderBST(struct Node *node) {
    if(node == NULL)
        return;

    postorderBST(node->left);
    postorderBST(node->right);
    _processNode(node->val);
}


void inorderBST(struct Node *node) {
    if(node == NULL)
        return;

    inorderBST(node->left);
    _processNode(node->val);
    inorderBST(node->right);
}


void depthFirstBST(struct BST *tree) {
    postorderBST(tree->root);
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
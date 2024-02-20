#ifndef BST_H
#define BST_H

#include "../type.h"

void initBST(struct BST *tree);
int containsBST(struct BST *tree, TYPE val);
int _containsNode(struct Node *node, TYPE val);
void addBST(struct BST *tree, TYPE val);
struct Node * _addNode(struct Node *node, TYPE val);

void preorderBST(struct Node *node);
void postorderBST(struct Node *node);
void inorderBST(struct Node *node);
void depthFirstBST(struct BST *tree);
void topDownBST(struct BST *tree);

/* Don't have to implement; just for ease of testing */
void freeBST(struct BST *tree);

#endif
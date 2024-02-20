#include "_helpers.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void _print_bst(struct Node *node, int indent, bool connect[]);


void print_dlist(struct DList *list) {
    struct DLink *link;

    printf("Data (front to back): ");
    link = list->frontSentinel->next;
    if(link != list->backSentinel) {
        printf("%d", link->value);
        link = link->next;
    }
    while(link != list->backSentinel) {
        printf(", %d", link->value);
        link = link->next;
    }

    printf("\nData (back to front): ");
    link = list->backSentinel->prev;
    if(link != list->frontSentinel) {
        printf("%d", link->value);
        link = link->prev;
    }
    while(link != list->frontSentinel) {
        printf(", %d", link->value);
        link = link->prev;
    }

    printf("\n");
}


void print_hash_table(struct HashTable *table) {
    int i, char_len;
    struct DataElem *link;
    
    printf("Elements in hash table: %d\n", table->count);
    printf("Buckets in hash table: %d\n", table->tablesize);
    printf("Data (by bucket):\n");

    if(table->table == NULL)
        return;
    
    char_len = floor(log10(abs(table->tablesize))) + 1;

    for(i = 0; i < table->tablesize; i++) {
        printf("    %*d| ", char_len, i);
        link = table->table[i];

        if(link != NULL) {
            printf("\"%s\": %d", link->key, link->val);
            link = link->next;
        }

        while(link != NULL) {
            printf(", \"%s\": %d", link->key, link->val);
            link = link->next;
        }

        printf("\n");
    }
}


void print_bst(struct BST *tree) {
    bool connect[] = {false};

    printf("Nodes in binary search tree: %d\n", tree->size);
    _print_bst(tree->root, 0, connect);
}

void _print_bst(struct Node *node, int indent, bool connect[]) {
    int i;
    bool *new_connect;

    /* Indent to appropriate level for this part of BST */
    for(i = 0; i < indent; i++) {
        if(i < 1 || !connect[i - 1])
            printf("    ");
        else
            printf("│   ");
    }
    
    /* Draw placeholder for node */
    if(indent == 0)
        printf("─── ");
    else if(connect[indent - 1])
        printf("├── ");
    else
        printf("└── ");

    /* Quit if no node */
    if(node == NULL) {
        printf("\n");
        return;
    }

    /* Draw value */
    printf("%d\n", node->val);

    /* No need to draw 2 empty children */
    if(node->left == NULL && node->right == NULL)
        return;

    /* Get connection rules for children */
    new_connect = (bool*) malloc((indent + 1) * sizeof(bool));
    for(i = 0; i < indent; i++)
        new_connect[i] = connect[i];
    new_connect[indent] = true;


    _print_bst(node->left, indent + 1, new_connect);
    new_connect[indent] = false;
    _print_bst(node->right, indent + 1, new_connect);

    free(new_connect);
}


bool get_input(int argc, char **argv, int *size) {
    if (argc != 2) {
        printf("Please call this function with 1 argument: \n");
        printf("    1. The number of elements to add when initially adding to each data structure\n");
        return false;
    }

    if (atoi(argv[1]) < 0) {
        printf("Please enter a non-negative size\n");
        return false;
    }

    *size = atoi(argv[1]);
    return true;
}
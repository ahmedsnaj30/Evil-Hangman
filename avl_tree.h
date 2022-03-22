#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <stdio.h>
#include "status.h"
#include "generic_vector.h"
#include "my_string.h"

typedef void* AVL;

struct node;
typedef struct node Node;

typedef struct tree
{
        Node* root;
}Tree;

struct node
{
        MY_STRING key;
        GENERIC_VECTOR words;
        Node* left;
        Node* right;
       // int height;
};
typedef struct node Node;

Tree* init_default(void);

Node* avl_newNode(MY_STRING key, MY_STRING word);

Status tree_insert(Tree* tree, MY_STRING key, MY_STRING shword);

Status avl_insert(Node** ppNode, MY_STRING key, MY_STRING word);

int max (int num1, int num2);

void avl_destroy_helper(Node* root);

void avl_destroy(Tree** phAVL);

void generic_vector_swap(GENERIC_VECTOR* vector, GENERIC_VECTOR* vector2);

GENERIC_VECTOR* findMax (Tree** tree);

void findMax_helper(Node* pNode, Node** ppNode, int* size);

void inorder_tree_print(Node* root);

#endif

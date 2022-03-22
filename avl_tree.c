#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "my_string.h"
#include "generic_vector.h"
#include "status.h"
#include "avl_tree.h"

Tree* init_default(void)
{
	Tree* node = (Tree*)malloc(sizeof(Tree));
	if(node != NULL)
	{
		node->root = NULL;
	}	
	return (AVL)node;
}

Node* avl_newNode(MY_STRING key, MY_STRING word)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if(node == NULL)
	{
        	return NULL;
	}
	node->key = my_string_init_default();
	my_string_assignment(&node->key, key);
	node->words = generic_vector_init_default((ITEM)my_string_assignment,my_string_destroy);
	my_string_assignment(&(node->key),(ITEM)key);
	generic_vector_push_back(node->words, (ITEM)word);	
	node->left = NULL;
	node->right = NULL;

	return node;
}

Status tree_insert(Tree* tree, MY_STRING key, MY_STRING shword)
{
	Tree* tempTree = (Tree*)tree;
	if(tempTree == NULL)
	{
		return FAILURE;
	}

	return avl_insert(&(tempTree->root), key, shword);
}

Status avl_insert(Node** ppNode, MY_STRING key, MY_STRING word)
{	
	Node* node;
	
	if(*ppNode == NULL)//error
	{
		node = avl_newNode(key, word);
		*ppNode = node; 
		return SUCCESS;
	}
	if(my_string_compare(key, (*ppNode)->key) == 1)
	{
		avl_insert(&((*ppNode)->left), key, word);
	}
	if(my_string_compare(key,(*ppNode)->key) == -1)
	{
		avl_insert(&((*ppNode)->right), key, word);	
	}
	if(my_string_compare(key,(*ppNode)->key) == 0) 
	{
		generic_vector_push_back((*ppNode)->words, (ITEM)word);
	}

	return SUCCESS;
}

int max (int num1, int num2)
{
	return (num1 > num2)? num1 : num2;
}

void avl_destroy_helper(Node* root){
        if(root != NULL){
                free(root->key);
                free(root->words);
                avl_destroy_helper(root->left);
                avl_destroy_helper(root->right);
                free(root);
        }
}

void avl_destroy(Tree** phAVL){
        Node* pNode = (Node*)*phAVL;
        if(pNode != NULL){
                avl_destroy_helper(pNode);
                free(pNode);
                *phAVL = NULL;
        }
}

void generic_vector_swap(GENERIC_VECTOR* vector, GENERIC_VECTOR* vector2)
{
	GENERIC_VECTOR temp; 
	
	temp = *vector;
	*vector = *vector2;
	*vector2 = temp;
}


GENERIC_VECTOR* findMax (Tree** tree)
{	
	int size = 0;
	int* max = &(size);

	Node* pNode;

	findMax_helper((*tree)->root, &pNode, max);

	return &(pNode->words);
}

void findMax_helper(Node* pNode, Node** ppNode, int* size)
{
	if(pNode != NULL)
	{
		findMax_helper(pNode->left, ppNode, size);
		if(*size < generic_vector_get_size(pNode->words))
		{
			*size = generic_vector_get_size(pNode->words);
			*ppNode = pNode;
		}
		findMax_helper(pNode->right,  ppNode, size);
	}
}

void inorder_tree_print(Node* root)
{

	if(root != NULL)
	{
		inorder_tree_print(root->left);
		printf("%5d: %s : %s\n", generic_vector_get_size(root->words), my_string_c_str(root->key), my_string_c_str(generic_vector_at(root->words, 0)));
		inorder_tree_print(root->right);
	}
}

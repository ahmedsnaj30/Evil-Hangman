#include <stdlib.h>
#include <stdlib.h>
#include "generic_vector.h"

struct generic_vector
{
	int size;
	int capacity;
	ITEM* data;
	Status(*item_assignment)(ITEM* pLeft, ITEM right);
	void (*item_destroy)(ITEM* phItem);
};
typedef struct generic_vector Generic_vector;

GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(ITEM* pLeft, ITEM right),
		void (*item_destroy)(ITEM* phItem))
{
	Generic_vector* pVector;
	int i;
	pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
	if(pVector != NULL)
	{
		pVector->size = 0;
		pVector->capacity = 1;
		pVector->item_assignment = item_assignment;
		pVector->item_destroy = item_destroy;
		pVector->data = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity);
		if(pVector->data == NULL)
		{
			free(pVector);
			return NULL;
		}
		for(i = 0; i < pVector->capacity; i++)
		{
			pVector->data[i] = NULL;
		}

	}
	return (GENERIC_VECTOR)pVector;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, ITEM value)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	ITEM* temp;
	int i;

	//if there is not enough room then make room.
	if (pVector->size >= pVector->capacity)
	{
		temp = (ITEM*)malloc(sizeof(ITEM) * pVector->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pVector->size; i++)
		{
			temp[i] = pVector->data[i];
		}
		//the rest of the thing...
		pVector->capacity *= 2;
		for (;i<pVector->capacity;i++)
		{
			temp[i] = NULL;
		}
		free(pVector->data);
		pVector->data = temp;
	}
	//BROKEN
	//pVector->data[pVector->size] = value;
	pVector->item_assignment(&(pVector->data[pVector->size]), value);
	pVector->size++;
	return SUCCESS;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->size;
}

int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	return pVector->capacity;
}

ITEM generic_vector_at(GENERIC_VECTOR hVector, int index)
{
	Generic_vector* pVector = (Generic_vector*)hVector;
	//is it out of bounds?
	if (index < 0 || index >= pVector->size)
	{
		return NULL;
	}

	return (pVector->data[index]);
}

void generic_vector_destroy(GENERIC_VECTOR* phVector)
{
	Generic_vector* pVector = (Generic_vector*)*phVector;
	int i;
	//destroy all of the objects in the vector
	for (i = 0; i < pVector->size; i++)
	{
		pVector->item_destroy(&(pVector->data[i]));
	}

	free(pVector->data);
	free(pVector);
	*phVector = NULL;
}

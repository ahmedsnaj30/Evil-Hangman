#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include <ctype.h>

struct my_string 
{
	int size;
	int capacity;
	char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
	//int length = 0;
	//int i = 0;
	My_string* pString;

	pString = (My_string*)malloc(sizeof(My_string));

	/*while(c_string[i] != '\0')
	{
		length++;
		i++;
	}*/

	if (pString != NULL)
	{
		pString -> size = 0;
		pString -> capacity = 7;
		pString -> data = (char*)malloc(sizeof(char)*pString->capacity);

		if(pString->data == NULL)
		{
			free(pString);
			return NULL;
		}
	}
	return pString;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
    int length = 0;
    int i;
    My_string* pString = (My_string*)malloc(sizeof(My_string));
    if (pString != NULL)
    {
        while (c_string[length]!= '\0')
        {
           length++;
        }
        pString->size = length;
        pString->capacity = length + 1;
        pString->data =(char*)malloc(sizeof(char) * pString->capacity);
        if (pString->data ==NULL)
        {
           free(pString);
           return NULL;
        }
	for(i=0; i<pString->size; i++)
	{
		pString->data[i] = c_string[i];
	}
    }
    return (MY_STRING)pString;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
       	return pString->capacity; 	
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	return pString->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	My_string* pLeftString = (My_string*)(hLeft_string);
	My_string* pRightString = (My_string*)(hRight_string);

	int i = 0;
	while(pLeftString->data[i] != '\0' && pRightString->data[i] != '\0')
	{
		if(pLeftString->data[i] > pRightString->data[i])
		{
			return 1; 
		}
		if(pLeftString->data[i] < pRightString->data[i])
		{
			return -1;
		}
		else
		{
			++i;
		}
        }
        return pLeftString->size - pRightString->size;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*)hMy_string;
	int num;
	char ch;
	char* temp;
	num = fscanf(fp,"%c", &ch);
	int i = 0;
	if(num == 1 && num != EOF)
	{
		pString->size = 0;	//instantializing size
		while (ch != EOF || ch != '\0')
		{
			if(pString->size >= pString->capacity)
			{
				temp = (char*)malloc(sizeof(char) * pString->capacity * 2);
				if(!temp)
				{
					free(temp);
					return FAILURE;
				}
				while (i < pString->size)
				{
					temp[i] = pString->data[i];
					++i;
				}
				free(pString->data);
				pString->data = temp;
				pString->capacity *= 2;
			}		
			if(ch == EOF || ch == '\n')
			{
				return SUCCESS;
			}
			else if(ch == ' ')
			{
				ungetc(ch, fp);	//name of your variable, then file pointer
				return SUCCESS;
			}
			pString->data[pString->size++] = ch; //putting brand new characters into the string
			num = fscanf(fp,"%c", &ch);
			if(num == EOF)
			{
				return SUCCESS;
			}
		}
	}
	return FAILURE;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*)hMy_string;
	int i;
	if(pString == NULL || fp == NULL)
	{
		return FAILURE;
	}
	for(i = 0; i < pString->size; i++)
	{
		fprintf(fp, "%c", pString->data[i]);
	}

	return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pString = (My_string*)hMy_string;
	char* temp;

	int i;

	if(pString->size >= pString->capacity)
	{
		temp = (char*)malloc(sizeof(char) * pString->capacity * 2);
		if(temp == NULL)
		{
			return FAILURE;
		}
		for(i = 0; i < pString->size; i++)
		{
			temp[i] = pString->data[i];
		}
		free(pString->data);
		pString->data = temp;
		pString->capacity *= 2;
	}
	pString->data[pString->size] = item;
	pString->size++;

	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;
	if(my_string_empty(hMy_string))
	{
		return FAILURE;
	}
	pString->size--;
	return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_string* pString = (My_string*)hMy_string;
	if(index > 0 || index >= pString->size)
	{
		return NULL;
	}
	return &(pString->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string)
{
	char* temp;
	int i;	
	My_string* pString = (My_string*)hMy_string;
	if(pString->data[pString->size] != '\0')
	{	
		temp = (char*)malloc(sizeof(char) * pString->capacity + 1);
		if(temp == NULL)
		{
			return NULL;
		}
		for(i = 0; i < pString->size; i++)
		{
			temp[i] = pString->data[i];
		}
		free(pString->data);
		temp[i] = '\0';		//trying to set the last character to NULL
		pString->data = temp;
		pString->capacity += 1;
	}

	return &(pString->data[0]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	My_string* pResult = (My_string*)hResult;
	My_string* pAppend = (My_string*)hAppend;
	int checkOld = pResult->size;
	int checkNew;
	char* temp;
	int i;
	int j;
	if((pResult->size + pAppend->size) >= pResult->capacity)
	{
		temp = (char*)malloc(sizeof(char) * (pResult->size + pAppend->size) + 1);
		if(temp == NULL)
		{
			return FAILURE;
		}
		for(i = 0; i < pResult->size; i++)
		{
			temp[i] = pResult->data[i];
		}
		free(pResult->data);
		pResult->data = temp;
		pResult->capacity = (pResult->size + pAppend->size) + 1;
	}
	for(j = 0; j < pAppend->size; ++j)
	{
		pResult->data[pResult->size] = pAppend->data[j];
		pResult->size++;
	}
	checkNew = pResult->size;
	if(checkNew > checkOld)
	{
		return SUCCESS;
	}
	else
	{
		return FAILURE;
	}
}

Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pString = (My_string*)hMy_string;

	return (Boolean)(pString->size <= 0);
}

void my_string_assignment(ITEM* pLeft, ITEM Right)
{
	My_string* hLeft = (My_string*)*pLeft;
	My_string* hRight = (My_string*)Right;

	if(hLeft == NULL)
	{
		hLeft = (My_string*)malloc(sizeof(My_string));
		
		if(hLeft)
		{
			hLeft->size = hRight->size;
			hLeft->capacity = hRight->capacity;
			hLeft->data = (char*)malloc(sizeof(char) * hLeft->capacity);
			if(hLeft->data == NULL)
			{
				free(hLeft->data);
				return;
			}
		}
		for(int i = 0; i < hLeft->size; i++)
		{
			hLeft->data[i] = hRight->data[i];
		}
		*pLeft = hLeft; //creates the deep copy part
	}
}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
	My_string* oldKey = (My_string*)current_word_family; //Old key, gets updated by whatever the user's guess is
	My_string* newKey = (My_string*)new_key; 	     //New key that combines the updated old key and the actual word
	My_string* wordKey = (My_string*)word;		     //Possible words

	newKey->size = 0; //resets newKey's size after each function call
	int i;

	for(i = 0; i < oldKey->size; i++)
	{
		my_string_push_back(newKey, oldKey->data[i]);
		//printf("%c", oldKey->data[i]);

	}
	
	i = 0;

	for(i = 0;i < wordKey->size; i++)
	{
		if(wordKey->data[i] == toupper(guess)||tolower(wordKey->data[i]) == tolower(guess))
		{
			newKey->data[i] = tolower(wordKey->data[i]);
		}
	}

	for(i = 0; i < oldKey->size; i++)
	{
		printf("%c", oldKey->data[i]);
	}

	printf("\n");

	for(i = 0; i < newKey->size; i++)
	{
		printf("%c", newKey->data[i]);
	}
	printf("\n");
			
	return SUCCESS;
}



void my_string_destroy(ITEM* pItem)
{
	My_string* pStr = (My_string*)*pItem;
	free(pStr->data);
	free(pStr);

	*pItem = NULL;
}

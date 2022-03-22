#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "avl_tree.h"

void clearKeyboardBuffer(void);

int main(int argc, const char* argv[]) 
{	
	GENERIC_VECTOR hVector[30];
	GENERIC_VECTOR currVector;
	MY_STRING currWord;
	MY_STRING hString;
	MY_STRING key;
	MY_STRING newKey = my_string_init_default();
	MY_STRING currWordFamily = my_string_init_default();
	MY_STRING guessed;
	int numGuess = 0;
	int currGuess = 0;
	char guess = '1';
	int noc;
	AVL newAvl;

	while (1)
	{	
		//Step 1
		for(i = 0; i < 30; i++) //initialize each index of the vector
        	{
                	hVector[i] = generic_vector_init_default((ITEM)my_string_assignment, my_string_destroy);
        	}
		currVector = generic_vector_init_default((ITEM)my_string_assignment, my_string_destroy);
	
			
		//
		FILE* fp = fopen("dictionary.txt", "r");
		
		currWord = my_string_init_default();

		while(my_string_extraction(hString, fp)) //extract each word to plug into hString
       		{
                	size = my_string_get_size(hString);
                	generic_vector_push_back(hVector[--size], hString);
			my_string_destroy(&currWorld);
			currWorld = my_string_init_default();
       		}
		fclose(fp);
		my_string_destroy(&currWord);
		//
		
		size = 0;
		
		printf("Enter the length:\n");
		scanf("%d", &size);
		clearKeyboardBuffer();

		while (size < 2|| size > 29 || size == 25 || size == 27 || size == 26 || size == 23)
		{
			printf("Enter a valid length:\n");
			scanf("%d", &size);	
			clearKeyboardBuffer();
		}
		
		//
		
		for(i = 0; i < 30; i++)
		{
			if(i != size)
				generic_vector_destroy(hVector[i]);
		}

		//
		
		for(i = 0; i < generic_vector_get_size(hVector[size]);
)

		for (i = 0; i < size; i++)
		{
			my_string_push_back(currWorldFamily, '-');
		}

		printf("Enter a number of guesses:\n");
		scanf("%d", &numGuess);
		while (numGuess <= 0)
		{
			printf("Enter a valid number of guesses:\n");
                        scanf("%d", &numGuess);
                        clearKeyboardBuffer();
		}

		

	}


	return 0;
}

void clearKeyboardBuffer(void) {
    char c;
    scanf("%c", &c);
    while (c != '\n') {
        scanf("%c", &c);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_string.h"
#include "generic_vector.h"

void int_destroy(ITEM* phItem);

Status int_assignment(ITEM* pLeft, ITEM right);

void clear_keyboard_buffer(void);

int main(int argc, char* argv[]){
	/*int integer1;
	int integer2;

	int **p = (int**) malloc(sizeof(int)*100);//First "bookend" allocates space

	printf("Hello world! I have created a dynamic 2d-array of 20x30 integers!\n");

	integer1 = 0;
	while(integer1 < 20) {
		p[integer1] = (int*)malloc(sizeof(int)*30);
	       	for(integer2 = 0; integer2 < 30; integer2++){
			p[integer1][integer2] = integer1 + integer2;
			printf("%3d", p[integer1][integer2]);
		}
		integer1++;
		printf("\n");
	}
	for (integer1 = 0; integer1 < 20; integer1++){
		free(p[integer1]);
	}

	free(p); //Second bookend cleans up the space
	p = NULL;

	return 0;*/
	//hMy_string = my_string_init_default();
	
	//-------------------Lab 3-----------------------------------------------------------
	/*
	MY_STRING hMy_string = NULL;
	FILE* fp;
	
	hMy_string = my_string_init_default();
	fp = fopen("dictionary.txt", "r");
	//hMy_string = my_string_init_c_string("hi");
	
	//MY_STRING string1 = my_string_init_c_string("Blok");
       	//MY_STRING string2 = my_string_init_c_string("med");	

	//printf("The capacity of the string is %d\n", my_string_get_capacity(hMy_string));

	//printf("The size of the string is %d\n", my_string_get_size(hMy_string));

	//printf("The number of the string returned is %d\n", my_string_compare(string1, string2));
	

	while(my_string_extraction(hMy_string, fp))
	{
		if(my_string_get_size(hMy_string) == 5)
		{
			my_string_insertion(hMy_string, stdout);
			printf("\n");
		}
	}


	my_string_destroy(&hMy_string);
	fclose(fp);*/
	//my_string_destroy(&string1);
	//my_string_destroy(&string2);
	//-----------------------------------------------------------------------------------
	
	//lab 4	
/*	MY_STRING string1 = my_string_init_default();
	MY_STRING string2 = my_string_init_default();
	
	if(my_string_empty(string1))
	{
		printf("string is empty right now\n");
	}

	my_string_push_back(string1, 'd');
	my_string_push_back(string1, 'o');
	my_string_push_back(string1, 'g');
	
	printf("%c\n", *my_string_at(string1, 0)); //we're dereferencing the address to get the character of a particular index

	my_string_push_back(string2, 'c');
	my_string_push_back(string2, 'a');
	my_string_push_back(string2, 't');

	my_string_pop_back(string1);
	printf("%s\n", my_string_c_str(string1));
	
	my_string_concat(string1, string2);

	printf("%s\n", my_string_c_str(string1));*/

	//lab 6 
	/*
	MY_STRING string[100];
	int i;
	for(i = 0; i < 100; i++)
	{
		string[i] = NULL;
	}
	string[0] = my_string_init_c_string("COPY ME!");
	
	for(i = 1; i < 100; i++)
	{
		my_string_assignment(&string[i], string[0]);
	}

	for(i = 0; i < 100; i++)
	{	
		my_string_insertion(string[i], stdout);
		printf("\n");
		my_string_destroy(&string[i]);
	}

	
	return 0;
	//Lab 7------------------------------------------------------------------
	*/
	/*
	MY_STRING hString = my_string_init_default();
	GENERIC_VECTOR hVector[29];
	
	int i;
	int size;
	int wordCount = 1;

	FILE* fp = fopen("dictionary.txt", "r");

	for(i = 0; i < 29; i++) //initialize each index of the vector
	{
		hVector[i] = generic_vector_init_default((ITEM)my_string_assignment, my_string_destroy);
	}

	while(my_string_extraction(hString, fp)) //extract each word to plug into hString
	{
		size = my_string_get_size(hString);
		generic_vector_push_back(hVector[--size], hString); //--size properly gets the size of each word and puts it at the correct index, size-- updates incorrectly
	}

	for(i = 0; i < 29; i++) //prints the word count of each word 
	{
		printf("%d: ", wordCount);
	       	wordCount++;
		printf("%d\n", generic_vector_get_size(hVector[i]));
	}

	for(i = 0; i < 29; i++) //Delete the vector at every index
	{
		generic_vector_destroy((GENERIC_VECTOR)&(hVector[i]));
	}

	my_string_destroy(&hString);
	fclose(fp);
	*/
	//lab 8----------------------------------------------------------------------
	
	MY_STRING oldKey = my_string_init_c_string("--ppy");
	MY_STRING word = my_string_init_c_string("happy");
	MY_STRING newKey = my_string_init_default();
	char guess;

	printf("guess\n");
	scanf("%c",&guess);
	clear_keyboard_buffer();

	get_word_key_value(oldKey, newKey, word, guess);

	my_string_destroy(&oldKey);
	my_string_destroy(&word);

	//second test case: The
	oldKey = my_string_init_c_string("---");
	word = my_string_init_c_string("The");

	printf("guess\n");
	

	scanf("%c",&guess);
	clear_keyboard_buffer();
	get_word_key_value(oldKey, newKey, word, guess);

	my_string_destroy(&oldKey);
	my_string_destroy(&word);

	//third test case: Truck
	oldKey = my_string_init_c_string("-----");
	word = my_string_init_c_string("Truck");

	printf("guess\n");
	scanf("%c",&guess);
	clear_keyboard_buffer();

	get_word_key_value(oldKey, newKey, word, guess);

	my_string_destroy(&oldKey);
	my_string_destroy(&word);
	my_string_destroy(&newKey);

	//fourth test case: awesome
	oldKey = my_string_init_c_string("--e---e");
	word = my_string_init_c_string("awesome");
	newKey = my_string_init_default();

	printf("guess\n");
	scanf("%c",&guess);
	clear_keyboard_buffer();

	get_word_key_value(oldKey, newKey, word, guess);

	my_string_destroy(&oldKey);
	my_string_destroy(&word);
	my_string_destroy(&newKey);
	
	return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    int noc;

    noc = scanf("%c", &c);

    while (noc == 1 && c != '\n')
    {
        noc = scanf("%c", &c);
    }
}

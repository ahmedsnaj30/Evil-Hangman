#include <stdlib.h>
#include <stdlib.h>
#include "my_string.h"
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	hString = my_string_init_default();

	if(hString == NULL)
	{
		strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default return NULL", length);
		return FAILURE;
	}
	else 
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
 MY_STRING hString = NULL;
 Status status;
 hString = my_string_init_default();
 if(my_string_get_size(hString) != 0)
	{
	status = FAILURE;
	printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	"Did not receive 0 from get_size after init_default\n", length);
 }
 else
 	{
	status = SUCCESS;
	strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	, length);
	}
	my_string_destroy(&hString);
	return status;
}

Status ashaheen3_get_capacity(char* buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	Status status;
	
	my_string_push_back(hString, 'B');
	my_string_push_back(hString, 'r');
	my_string_push_back(hString, 'u');
	my_string_push_back(hString, 'h');

	if(my_string_get_capacity(hString))
	{
		status = SUCCESS;
	        strncpy(buffer, "ashaheen3_get_capacity\n", length);

	}
	else 
	{
		status = FAILURE;
	        printf("Expected a size of 7.\n");
        	strncpy(buffer, "ashaheen3_get_capacity\n"
        	"Did not receive 0 from ashaheen3_get_capacity after init_default\n", length);

	}
	my_string_destroy(&hString);
	return status;
}

Status ashaheen4_get_size(char* buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	Status status;

	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');

	if(my_string_get_size(hString))
	{
		status = SUCCESS;
		strncpy(buffer, "ashaheen4_get_size\n", length);

	}
	else
	{
		status = FAILURE;
		printf("Expected a size of 7.\n");
		strncpy(buffer, "ashaheen4_get_size(\n"
		"Did not receive 0 from ashaheen4_get_size after init_default\n", length);

	}
	my_string_destroy(&hString);
	return status;

}

Status ashaheen5_string_compare(char* buffer, int length)
{
        MY_STRING hString = my_string_init_c_string("Bro");
	MY_STRING hString2 = my_string_init_c_string("Bruh");
        Status status;

        if(my_string_compare(hString, hString2))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen5_string_compare\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen5_string_compare(\n"
                "Did not receive 0 from ashaheen5_string_compare after init_default\n", length);

        }
        my_string_destroy(&hString);
	my_string_destroy(&hString2);
        return status;

}

Status ashaheen6_string_push_back(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bro");
        Status status;

        if(my_string_push_back(hString, 'h'))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen6_string_push_back\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen6_string_push_back\n"
                "Did not receive 0 from ashaheen6_string_push_back after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;
}

Status ashaheen7_string_pop_back(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("B");
        Status status;

        if(my_string_pop_back(hString))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen7_string_pop_back\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen7_string_pop_back\n"
                "Did not receive 0 from ashaheen7_string_pop_back after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;

}

Status ashaheen8_string_at(char* buffer, int length)
{
        MY_STRING hString = my_string_init_c_string("Bruh");
        Status status;

        if(my_string_at(hString, 0))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen8_string_at\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen8_string_at\n"
                "Did not receive 0 from ashaheen8_string_at after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;

}

Status ashaheen9_string_c_str(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bruh");
	Status status;

        if(my_string_c_str(hString))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen9_string_c_str\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen9_string_c_str\n"
                "Did not receive 0 from ashaheen9_string_c_str after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;
}

Status ashaheen10_string_concat(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bro");
        MY_STRING hString2 = my_string_init_c_string("Bruh");
        Status status;

        if(my_string_concat(hString,hString2))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen10_string_concat\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen10_string_concat\n"
                "Did not receive 0 from ashaheen10_string_concat after init_default\n", length);

        }
        my_string_destroy(&hString);
	my_string_destroy(&hString2);
        return status;
}

Status ashaheen11_string_insertion(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bro");
        Status status;
	FILE* fp = fopen("simple.txt", "r");

        if(my_string_insertion(hString,fp))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen11_string_insertion\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen11_string_insertion\n"
                "Did not receive 0 from ashaheen11_string_insertion after init_default\n", length);

        }
	fclose(fp);
        my_string_destroy(&hString);
        return status;

}

Status ashaheen12_string_extraction(char* buffer, int length)
{
        MY_STRING hString = my_string_init_c_string("Bro");
        Status status;
        FILE* fp = fopen("simple.txt", "r");

        if(my_string_extraction(hString,fp))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen12_string_extraction\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen12_string_extraction\n"
                "Did not receive 0 from ashaheen12_string_extraction after init_default\n", length);

        }
        fclose(fp);
        my_string_destroy(&hString);
        return status;

}

Status ashaheen13_string_empty(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bro");
        Status status;

        if(my_string_empty(hString)==0)
        {	
                status = SUCCESS;
                strncpy(buffer, "ashaheen13_string_empty(\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected string to be empty.\n");
                strncpy(buffer, "ashaheen13_string_empty\n"
                "Did not receive 0 from ashaheen13_string_empty after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;
}


Status ashaheen14_string_destroy(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bro");
	my_string_destroy(&hString);
	Status status;
	if(hString == NULL)
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen14_string_destroy\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected string to be destroyed.\n");
                strncpy(buffer, "ashaheen14_string_destroy\n"
                "Did not receive 0 from ashaheen14_string_destroy after init_default\n", length);
	}
	return status;
}

Status ashaheen15_string_init_c_string(char* buffer, int length)
{
	MY_STRING hString = NULL;

        hString = my_string_init_c_string("Bruh");

        if(hString == NULL)
        {
               strncpy(buffer, "ashaheen15_string_init_c_string\n" "my_string_init_default return NULL", length);
               return FAILURE;
        }
        else
        {
                my_string_destroy(&hString);
                strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
                return SUCCESS;
        }
	
}

Status ashaheen16_string_get_size_c_str(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bruh");
        Status status;

        if(my_string_get_size(hString))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen16_string_get_size_c_str\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen16_string_get_size_c_str\n"
                "Did not receive 0 from ashaheen16_string_get_size_c_str after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;

}

Status ashaheen17_string_get_capacity_c_str(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("Bruh");
        Status status;

        if(my_string_get_capacity(hString))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen17_string_get_capacity_c_str\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen17_string_get_capacity_c_str\n"
                "Did not receive 0 from ashaheen17_string_get_capacity_c_str after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;
}

Status ashaheen18_string_compare_init_default(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;
	
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');	
	
	MY_STRING hString2 = my_string_init_default();

	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'o');

        if(my_string_compare(hString, hString2))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen18_string_compare_init_default\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen5_string_compare(\n"
                "Did not receive 0 from ashaheen18_string_compare_init_default after init_default\n", length);

        }
        my_string_destroy(&hString);
        my_string_destroy(&hString2);
        return status;

}

Status ashaheen19_string_push_back_init_default(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
	Status status;	
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');

        if(my_string_push_back(hString, 'h'))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen19_string_push_back_init_default\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen19_string_push_back_init_default\n"
                "Did not receive 0 from ashaheen19_string_push_back_init_default after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;
}


Status ashaheen20_string_pop_back(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;

	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');

        if(my_string_pop_back(hString))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen20_string_pop_back\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen20_string_pop_back\n"
                "Did not receive 0 from ashaheen20_string_pop_back after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;

}


Status ashaheen21_string_at(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;

        my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');

        if(*my_string_at(hString, 0))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen8_string_at\n", length);

        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen8_string_at\n"
                "Did not receive 0 from ashaheen8_string_at after init_default\n", length);

        }
        my_string_destroy(&hString);
        return status;

}

Status ashaheen22_string_concat_init_default(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');
        MY_STRING hString2 = my_string_init_default();
	my_string_push_back(hString2, 'B');
        my_string_push_back(hString2, 'r');
        my_string_push_back(hString2, 'o');
        Status status;

        if(my_string_concat(hString,hString2))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen22_string_concat_init_default\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen22_string_concat_init_default\n"
                "Did not receive 0 from ashaheen22_string_concat_init_default after init_default\n", length);

        }
        my_string_destroy(&hString);
        my_string_destroy(&hString2);
        return status;
}


Status ashaheen23_string_insertion_init_default(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');
        FILE* fp = fopen("simple.txt", "r");

        if(my_string_insertion(hString,fp))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen23_string_insertion_init_default\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen23_string_insertion_init_default\n"
                "Did not receive 0 from ashaheen23_string_insertion_init_default after init_default\n", length);

        }
        fclose(fp);
        my_string_destroy(&hString);
        return status;

}

Status ashaheen24_string_insertion_init_default(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');

        FILE* fp = fopen("simple.txt", "r");

        if(my_string_insertion(hString,fp))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen24_string_insertion_init_default\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen24_string_insertion_init_default\n"
                "Did not receive 0 from ashaheen24_string_insertion_init_default after init_default\n", length);

        }
        fclose(fp);
        my_string_destroy(&hString);
        return status;

}


Status ashaheen25_string_extraction(char* buffer, int length)
{
        MY_STRING hString = my_string_init_default();
        Status status;
	my_string_push_back(hString, 'B');
        my_string_push_back(hString, 'r');
        my_string_push_back(hString, 'u');
        my_string_push_back(hString, 'h');
        FILE* fp = fopen("simple.txt", "r");

        if(my_string_extraction(hString,fp))
        {
                status = SUCCESS;
                strncpy(buffer, "ashaheen25_string_extraction\n", length);
        }
        else
        {
                status = FAILURE;
                printf("Expected a size of 7.\n");
                strncpy(buffer, "ashaheen25_string_extraction\n"
                "Did not receive 0 from ashaheen25_string_extraction after init_default\n", length);

        }
        fclose(fp);
        my_string_destroy(&hString);
        return status;

}


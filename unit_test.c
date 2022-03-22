#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_init_default_returns_nonNULL,
 test_get_size_on_init_default_returns_0,
 ashaheen3_get_capacity,
 ashaheen4_get_size,
 ashaheen5_string_compare,
 ashaheen6_string_push_back,
 ashaheen7_string_pop_back,
 ashaheen8_string_at,
 ashaheen9_string_c_str,
 ashaheen10_string_concat,
 ashaheen11_string_insertion,
 ashaheen12_string_extraction,
 ashaheen13_string_empty,
 ashaheen14_string_destroy,
 ashaheen15_string_init_c_string,
 ashaheen16_string_get_size_c_str,
 ashaheen17_string_get_capacity_c_str,
 ashaheen18_string_compare_init_default,
 ashaheen19_string_push_back_init_default,
 ashaheen20_string_pop_back,
 ashaheen21_string_at,
 ashaheen22_string_concat_init_default,
 ashaheen23_string_insertion_init_default,
 ashaheen24_string_insertion_init_default,
 ashaheen25_string_extraction
 };
 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;
 for(i=0; i<number_of_functions; i++)
 {
 if(tests[i](buffer, 500) == FAILURE)
 {
 printf("FAILED: Test %d failed miserably\n", i);
 printf("\t%s\n", buffer);
 failure_count++;
 }
 else
 {
// printf("PASS: Test %d passed\n", i);
// printf("\t%s\n", buffer);
 success_count++;
 }
 }
 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}

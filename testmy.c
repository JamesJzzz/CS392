#include "my.h"
#include <stdio.h>

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/


int main(int argc, char **argv){

/*
	printf("---Printing out the tests for my_char---\n");
	my_char('h'); 
	printf("\n");
	my_char(' ');
	printf("\n");
	my_char('\0');
	printf("\n");

	printf("---Printing out the tests for my_int---\n");
	my_int(1234567);
	printf("\n");
	my_int(0);
	printf("\n");
	my_int(1);
	printf("\n");
	my_int(-1);
	printf("\n");
	my_int(6.7);
	printf("\n");
	my_int('\0');
	printf("\n");

	printf("---Printing out the tests for my_num_base---\n");
	my_num_base(6, '\0');
	printf("\n");
	my_num_base(-4, "1010101");
	printf("\n");
	my_num_base(9, "ABADF");
	printf("\n");
	my_num_base(0, "550555");
	printf("\n");




	printf("---Printing out the tests for my_aplha---\n");
	my_alpha('\0');
	printf("\n");

	printf("---Printing out the tests for my_digits---\n");
	my_digits('\0');
	printf("\n");

	printf("---Printing out the tests for my_strindex---\n");
	my_strindex('\0', '\0');
	printf("\n");
	my_strindex("abcd", '\0');
	printf("\n");
	my_strindex('\0', 'a');
	printf("\n");
	my_strindex("restre", '\0');
	printf("\n");
	my_strindex("sunset", 'u');
	printf("\n");
	my_strindex("1234", '4');
	printf("\n");
	my_strindex("HelloWorld", 'o');
	printf("\n");
	my_strindex("wOwowOw", 'o');
	printf("\n");
	my_strindex("eeeeee", 'e');
	printf("\n");
	my_strindex("susana", 'A');
	printf("\n");



	printf("---Printing out the tests for my_strrindex---\n");
	my_strrindex('\0', '\0');
	printf("\n");
	my_strrindex("abcd", '\0');
	printf("\n");
	my_strrindex('\0', 'a');
	printf("\n");
	my_strrindex("restre", '\0');
	printf("\n");
	my_strrindex('\0', 'b');
	printf("\n");
	my_strrindex("sunset", 'u');
	printf("\n");
	my_strrindex("1234", '4');
	printf("\n");
	my_strrindex("HelloWorld", 'o');
	printf("\n");
	my_strrindex("wOwowOw", 'O');
	printf("\n");
	my_strrindex("eeeeee", 'e');
	printf("\n");
	my_strindex("susana", 'A');
	printf("\n");


	printf("---Printing out the tests for my_strlen---\n");
	my_strlen('\0');
	printf("\n");
	my_strlen("ajsfgasdg");
	printf("\n");
	my_strlen("a");
	printf("\n");
	my_strlen("abcd");
	printf("\n");

	printf("---Printing out the tests for my_revstr---\n");
	my_revstr('\0');
	printf("\n");
	my_revstr('\0');
	printf("\n");
	my_revstr("b");
	printf("\n");
	my_revstr("ab");
	printf("\n");
	my_revstr("hello world");
	printf("\n");
	my_revstr("aaa");
	printf("\n");
*/
	/*
	Test for part 2
	*/
	printf("---Printing out the tests for my_strfind---\n");
	my_strfind('\0', '\0'); 
	printf("\n");
	my_strfind("abcd", '\0');
	printf("\n");
	my_strfind('\0', 'b');
	printf("\n");
	my_strfind("stevens", 'v');
	printf("\n");
	my_strfind("kaitlynn", 'A');
	printf("\n");
	my_strfind("HelloWorld", 'o');
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strrfind---\n");
	my_strrfind('\0', '\0'); 
	printf("\n");
	my_strrfind("abcd", '\0');
	printf("\n");
	my_strrfind('\0', 'b');
	printf("\n");
	my_strrfind("stevens", 'v');
	printf("\n");
	my_strrfind("kaitlynn", 'A');
	printf("\n");
	my_strrfind("HelloWorld", 'o');
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strcmp---\n");
	my_int(my_strcmp('\0', '\0')); 
	printf("\n");
	my_int(my_strcmp("hello", '\0'));
	printf("\n");
	my_int(my_strcmp('\0', "world"));
	printf("\n");
	my_int(my_strcmp("hello", "hello"));
	printf("\n");
	my_int(my_strcmp("jdbsuekc", "world"));
	printf("\n");
	my_int(my_strcmp("world", "jdbsuekc"));
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strncmp---\n");
	my_int(my_strncmp('\0', '\0', 4)); 
	printf("\n");
	my_int(my_strncmp("hello", '\0', 3));
	printf("\n");
	my_int(my_strncmp('\0', "hello", 3));
	printf("\n");
	my_int(my_strncmp("stevens", "selfie", 6));
	printf("\n");
	my_int(my_strncmp("hell", "hello", 4));
	printf("\n");
	my_int(my_strncmp("helpme", "whyyyyyy", 10));
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strcpy---\n");
	my_strcpy('\0', '\0'); 
	printf("\n");
	my_strcpy("hello", '\0');
	printf("\n");
	my_strcpy('\0', "world");
	printf("\n");
	my_strcpy("hello", "world");
	printf("\n");
	my_strcpy("stevens", "selfie");
	printf("\n");
	my_strcpy("helpme", "whyyyyyy");
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strncpy---\n");
	my_strncpy('\0', '\0', 3); 
	printf("\n");
	my_strncpy("hello", '\0', 4);
	printf("\n");
	my_strncpy('\0', "world", 7);
	printf("\n");
	my_strncpy("hello", "world", 2);
	printf("\n");
	my_strncpy("stevens", "selfie", 4);
	printf("\n");
	my_strncpy("helpme", "whyyyyyy", 4);
	printf("\n");
	printf("\n");


	printf("---Printing out the tests for my_strcat---\n");
	my_strcat('\0', '\0'); 
	printf("\n");
	my_strcat("hello", '\0');
	printf("\n");
	my_strcat('\0', "world");
	printf("\n");
	my_strcat("hello", "world");
	printf("\n");
	my_strcat("stevens", "selfie");
	printf("\n");
	my_strcat("whyyyyyy,", "helpme");
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strdup---\n");
	my_strdup('\0'); 
	printf("\n");
	my_strdup("hello");
	printf("\n");
	my_strdup("world");
	printf("\n");
	my_strdup("from");
	printf("\n");
	my_strdup("stevens");
	printf("\n");
	my_strdup("2016");
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strconcat---\n");
	my_strconcat('\0', '\0'); 
	printf("\n");
	my_strconcat("hello", '\0');
	printf("\n");
	my_strconcat('\0', "world");
	printf("\n");
	my_strconcat("hello", "world");
	printf("\n");
	my_strconcat("stevens", "selfie");
	printf("\n");
	my_strconcat("whyyyyyy,", "helpme");
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_strnconcat---\n");
	my_strnconcat('\0', '\0', 4); 
	printf("\n");
	my_strnconcat("hello", '\0', 3);
	printf("\n");
	my_strnconcat('\0', "world", 3);
	printf("\n");
	my_strnconcat("hello", "world", 4);
	printf("\n");
	my_strnconcat("stevens", "selfie", 10);
	printf("\n");
	my_strnconcat("whyyyyyy,", "helpme", 4);
	printf("\n");
	printf("\n");

	printf("---Printing out the tests for my_atoi---\n");
	my_int(my_atoi("5")); 
	printf("\n");
	my_int(my_atoi("-5"));
	printf("\n");
	my_int(my_atoi("--5"));
	printf("\n");
	my_int(my_atoi("a-b54sc7-d"));
	printf("\n");
	my_int(my_atoi("abcd"));
	printf("\n");
	my_int(my_atoi('\0'));
	printf("\n");
	printf("\n");


	return 0;
} 
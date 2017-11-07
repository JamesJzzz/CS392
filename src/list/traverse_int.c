/*
 Prints all the elems as ints separated by a space
*/
#include "mylist.h"

void traverse_int(struct s_node* head)
{
	if(head != NULL)
	{
		while(head != NULL)
		{
			print_int(head);
			my_char(' ');
			head = head->next;
		}
	}
}
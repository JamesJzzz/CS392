/*
 Prints all the elems as strings separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/
#include "mylist.h"

void debug_string(struct s_node* head)
{
	
	if(head != NULL)
	{
		while(head != NULL)
		{
			my_char('(');
			if(head->prev == NULL)
				my_str("NULL <- ");
			else
			{
				print_string(head->prev);
				my_str(" <- ");
			}
			print_string(head);
			if(head->next == NULL)
				my_str(" -> NULL)");
			else
			{
				my_str(" -> ");
				print_string(head->next);
				my_str("), ");
			}
			head = head->next;
		}
	}
}
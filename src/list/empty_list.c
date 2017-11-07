/*
 Frees all the nodes in the list.
 CHALLENGE: Write in two lines (allowed to use other methods in 
 this assignment)
*/
#include "mylist.h"

void empty_list(struct s_node** head)
{
	while(head != NULL && *head != NULL)
		remove_last(head);
}
/*
prints all the elems as strings separated by a space
*/

#include "mylist.h"

void traverse_string(struct s_node* head){
	if(head !=NULL){
		while(head!= NULL){
			print_string(head);
			my_char(' ');
			head = head->next;
		}
	}
}
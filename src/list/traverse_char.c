/*
 Prints all the elems as chars separated by a space
*/
#include "mylist.h"

void traverse_char(struct s_node* head){
	
	if(head != NULL){
		while(head != NULL){
			print_char(head);
			my_char(' ');
			head = head->next;
		}
	}
}
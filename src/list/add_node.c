/*
insert a node at the beginning of the list.
will not add a NULL pointer, or a node with NULL elem.
*/
#include "mylist.h"

void add_node(struct s_node* node, struct s_node** head){
	
	if (node != NULL && head != NULL && node->elem != NULL){
		if (*head != NULL){
			node -> prev = (*head) -> prev;
			node -> next = (*head);
			if ((*head) -> prev != NULL){
				(*head)-> prev ->next = node;
			}
			(*head) -> prev = node;
			*head = node;
		}
		else{
			*head = node;
			node->prev = NULL;
			node->next = NULL;
		}
	}
}
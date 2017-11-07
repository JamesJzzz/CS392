/*
adds a node to the end of a list, 
will not take a NULL pointer or a node with a NULL elem.
*/
#include "mylist.h"

void append(struct s_node * node, struct s_node **head){
	struct s_node * current;
	if (node != NULL && head != NULL && node->elem != NULL){
		if (*head == NULL){
			add_node(node,head);
		}
		else{
			current = *head; 
			while(current->next != NULL)
				current = current->next;
			node->prev = current;
			node->next = current->next;
			current->next = node;
		}
	}
}
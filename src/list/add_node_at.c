/*
this function add a node at index n of a list, or at the end of 
a list if n is too large. like outside of the range.
*/
#include "mylist.h"

void add_node_at(struct s_node *node, struct s_node **head, int n){
	int i = 0;
	struct s_node *current;
	if (node != NULL && head != NULL){
		if (*head == NULL || n<= 0){
			add_node(node,head);
		}
		else if (n >= count_s_nodes(*head)){
			append(node,head);
		}
		else{
			current = *head;
			for (i = 0; i < n && current ->next != NULL; i++){
				current = current->next;
			}
			current->prev->next = node;
			node->prev = current->prev;
			node->next = current;
			current->prev = node;
		}
	}
}
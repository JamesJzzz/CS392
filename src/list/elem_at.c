
/*
 Returns a pointer to the elem at index n or the last node.
 Parse once.
*/

#include "mylist.h"

 void* elem_at(struct s_node* head, int n){
 	struct s_node *node = node_at(head,n);
 	if (node != NULL){
 		return node->elem;
 	}
 	else
 		return NULL;
 }
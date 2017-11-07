/*
this creates a new node with the elem and adds it to the head.
will not take a NULL elem.
*/
#include "mylist.h"

void add_elem(void * elem, struct s_node ** head){
	
	if (elem != NULL && head != NULL){
		struct s_node* newNode = new_node(elem, NULL,NULL);
		add_node(newNode, head);
	}
}
/*
this is will allow you to create a NULL node,
allocates and returns a new node with the given pointers.
*/


#include "mylist.h"

struct s_node* new_node(void* elem, struct s_node* next, struct s_node* previous){
	struct s_node *thenode = (struct s_node *)malloc(sizeof(struct s_node));
	thenode -> elem = elem;
	thenode -> next = next;
	thenode -> prev = previous;
	return thenode;
}

/*
this function returns the value of the length of the list
*/
#include "mylist.h"

int count_s_nodes(struct s_node * head){
	int i = 0;
	struct s_node *current = head;
	if (head != NULL){
		while (current -> next != NULL){
			i ++;
			current = current->next;
		}
		i++;
		return 1;
	}
	else
		return 0;
}
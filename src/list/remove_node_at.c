
/*
 Removes the node at index n or the last node.
 Parse once
*/
#include "mylist.h"

void *remove_node_at(struct s_node** head, int n){
	int i = 0;
	struct s_node *current;
	void* ret;
	if(head!= NULL){
		if(*head ==NULL || n<= 0){
			return remove_node(head);
		}
		else if(n >= count_s_nodes(*head)){
			return remove_last(head);
		}
		else{
			current = *head;
			for(i = 0; i<n && current->next != NULL; i++){
				current = current -> next;
			}
			current->prev->next = current->next;
			if(current->next != NULL){
				current->next->prev = current->prev;
			}
			ret = current -> elem;
			free(current);
			return ret;
		}
	}
	else{
		return NULL;
	}
}
/*
 Removes the last node from the list.
 Parse Once.
*/
#include "mylist.h"

 void* remove_last(struct s_node** head){
 	struct s_node *current;
 	void * ret;
 	if(head!= NULL && *head != NULL){
 		if((*head)->next == NULL)
		{
			ret = (*head)->elem;
			free(*head);
			*head = NULL;
			return ret;
		}
		else{
			current = *head;
			while(current->next != NULL){
				current = current-> next;
			}
			current->prev->next = NULL;
			ret = current->elem;
			free(current);
			return ret;
		}
 	}
 	else{
 		return NULL;
 	}
 }
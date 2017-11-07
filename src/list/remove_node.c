/* 
 Removes the first node from the list. Returns elem and frees the 
 node from memory.
 DOES NOT PARSE.
*/

 #include "mylist.h"

 void* remove_node(struct s_node** head){
 	void * ret;
 	struct s_node *newhead;
 	
 	if (head != NULL){
 		if (*head == NULL)
 			return NULL;
 		ret = (*head) -> elem;
 		if((*head)->next != NULL){
 			(*head)->next->prev = (*head)->prev;
 			if((*head)->prev != NULL)
 				(*head)->prev->next = (*head)->next;
 			newhead = (*head)->next;
 			free(*head);
 			*head = newhead;
 		}
 		else{
 			free(*head);
 			*head = NULL;
 		}
 		return ret;
 	}
 	else{
 		return NULL;
 	}
 }
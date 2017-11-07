/*
 Returns a pointer to the node at index n or the last node.
 Parse once
*/
 #include "mylist.h"

 struct s_node* node_at(struct s_node* head, int n){
 	int i = 0;
 	if(head!= NULL){
 		for (i = 0; i < n && head->next != NULL; i++){
 			head = head->next;
 		}
 		return head;
 	}
 	else{
 		return NULL;
 	}
 }

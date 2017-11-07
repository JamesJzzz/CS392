/*
 Prints all the elems as ints separated by a space in the format
 (NULL <- Elem -> Next elem), ..., (Previous elem <- Elem -> NULL) 
*/

 #include "mylist.h"

 void debug_int(struct s_node* head){
 	
 	if(head != NULL)
 	{
 		while(head != NULL){
 			my_char('(');
 			if (head->prev == NULL){
 				my_str("NULL <- ");
 			}
 			else{
 				print_int(head->prev);
 				my_str(" <- ");
 			}
 			print_int(head);
 			if(head->next == NULL){
 				my_str(" -> NULL)");
 			}
 			else{
 				my_str(" -> ");
 				print_int(head->next);
 				my_str("), ");
 			}
 			head = head->next;
 		}
 	}
 }
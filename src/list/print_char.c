#include "mylist.h"

/*
 Prints the elem of node as a char
*/

void print_char(struct s_node* node){
	if(node != NULL){
		char printing = (char)*(char *) (node->elem);
		my_char(printing);
	}
}
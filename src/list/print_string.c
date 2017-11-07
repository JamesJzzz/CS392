#include "mylist.h"

void print_string(struct s_node *node){
	if (node != NULL){
		char* printing = (char *) node->elem;
		my_str(printing);
	}
}
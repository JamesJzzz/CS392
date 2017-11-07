#include "mylist.h"

void print_int(struct s_node * node){
	if (node != NULL){
		int printing = (int)*((int *) node->elem);
		my_int(printing);
	}
}
/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"

void my_str(char* x){
if (x!= NULL){
	char* ptr = x;
	while (*ptr != '\0'){
		my_char(*ptr);
		ptr++;
	}
}
else{
	return;
}
}


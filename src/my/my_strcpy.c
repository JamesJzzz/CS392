#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char *my_strcpy(char *a, char *b){
	char *my_strdup(char *);
	char *src = my_strdup(b);
	int lensrc = my_strlen(src), i;
	if (a == NULL){
		return NULL;
	}
	else if(b == NULL){
		return a;
	}
	for (i = 0; i < lensrc; i++){
		a[i] = src[i];
	}
	a[i] = '\0';
	free(src);
	return a;
}
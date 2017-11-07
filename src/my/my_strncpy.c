#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char *my_strncpy(char *a, char *b, int i){
	char *my_strdup(char *);
	char *src = my_strdup(b);
	int lensrc = my_strlen(src);
	int x;

	if (a==NULL){
		return NULL;
	}
	else if(b == NULL){
		return a;
	}
	else if( i <= 0){
		return a;
	}
	if (lensrc > i){
		lensrc = i <0 ? 0 : i;
	}
	for (x= 0; x < lensrc; x++){
		a[x] = src[x];
	}
	a[x] = '\0';
	free(src);
	return a;

}
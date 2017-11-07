#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char *my_strcat(char *a, char *b){
	int x = 0;
	int y = 0;
	if (a ==NULL){
		return NULL;
	}
	else if (b == NULL){
		return a;
	}
	while (a[x] != '\0')
		x++;
	for ( y = 0; b[y] != '\0'; x++, y++)
		a[x] = b[y];
	a[x] = '\0';
	return a;
}
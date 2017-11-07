#include "my.h"

char *my_vect2str(char **a){
	int x = 0; 
	int y = 0;
	int z = 0;
	int lres = 0;
	char *res, *e= "";
	if (a == NULL){
		return NULL;
	}
	while(a[x] != NULL && a[x] != e){
		if (a[x] != e){
			while (a[x][y] != '\0'){
				lres++;
				y++;
			}
		}
		y=0;
		lres++;
		x++;
	}
	lres--;
	y = 0;
	x = 0;
	res = (char *)malloc(sizeof(char)* (lres + 1));
	while (a[x] != NULL){
		if(a[x] != e){
			while (a[x][y] != '\0'){
				res[z] = a[x][y];
				y++;
				z++;
			}
		}
		res[z++] = ' ';
		y = 0;
		x++;
	}
	res[--z] = '\0';
	return res;

}
#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char *my_strdup(char *a){
	char *nstr, *e = "";
	int lensrc = my_strlen(a), x;
	if (a == NULL){
		return NULL;
	}
	else if (a == e){
		nstr = malloc(sizeof (char) *1);
		nstr[0] = '\0';
		return nstr;
	}
	if (lensrc < 0){
		lensrc = 0;
	}
	nstr = (char *) malloc (sizeof (char)*(lensrc +1));
	for (x = 0; x< lensrc; x++){
		nstr[x]=a[x];
	}
	nstr[x] = '\0';
	return nstr;
}
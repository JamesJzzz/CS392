#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

int my_strncmp(char *a, char *b, int i){
	int lena = my_strlen(a), lenb = my_strlen(b);
	int x;
	int result = 0;
	lena = lena > i ? (i < 0 ? 0 : i) : lena;
	lenb = lenb > i ? (i < 0 ? 0 : i) : lenb;

	if (a == 0 || b == 0){
		return a == 0 && b == 0 ? 0 : a == 0 ? -1 : 1;
	}
	else if ( i <= 0 ){
		return 0;
	}
	for(x = 0; result == 0 && x< lena && x< lenb; x++){
		result = a[x] < b[x] ? -1 : a[x] == b[x] ? 0 : 1;
	}
	if (result == 0){
		result = lena < lenb ? -1 : lena == lenb ? 0 : 1;
	}
	return result;
}
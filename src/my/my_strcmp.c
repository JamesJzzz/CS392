#include "my.h"
/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

int my_strcmp(char *a, char *b){
	int lena;
	int lenb;
	int i;
	int result = 0;
	lena = my_strlen(a);
	lenb = my_strlen(b);
	if (a == 0 || b == 0){
		if (a == 0 && b == 0){
			return 0;
		}
		else{
			if (a == 0){
				return -1;
			}
			else{
				return 1;
			}
		}
	}
	for (i = 0; result == 0 && i < lena && i < lenb; i++){
		if (a[i] < b[i]){
			result = -1;
		}
		else {
			if (a[i] == b[i]){
				result = 0;
			}
			else{
				result = 1;
			}
		}
	}
	if (result == 0){
		if (lena<lenb){
			result = -1;
		}
		else {
			if(lena == lenb){
				result = 0;
			}
			else{
				result = 1;
			}
		}
	}
	return result;
}
#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char* my_strfind(char* a, char b){
	int index = -1;
	int x = 0;
	while (a != 0 && a[x] != '\0'){
		if (a[x] == b){
			if (index == -1){
				index = x;
			}
		}
		x++;
	}
	return &a[index];
}
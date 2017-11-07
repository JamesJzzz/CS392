#include "my.h"
/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/
int my_atoi(char *a){
	int result = 0;
	int x = 0;
	int y = 1;
	int z = 0;
	int i = 0;

	if (a == NULL){
		return 0;
	}
	while (a[x] != '\0' && z == 0){
		if ((a[x] >= '0' && a[x] <= '9') || a[x] == '-'){
			if (a[x] == '-'){
				if (i == 0){
					y *= -1;
				}
				else {
					z = 1;
				}
			}
			else {
				result *= 10;
				result += (a[x] - '0');
				i = 1;
			}
		}
		else{
			if ( i != 0){
				z =1;
			}
		}
		x++;
	}
	if (i == 1 ){
		result *= y;
		return result;
	}
	else {
		return 0;
	}
}
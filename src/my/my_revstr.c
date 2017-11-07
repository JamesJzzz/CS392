/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/
#include "my.h"


#include "my.h"

int my_revstr(char* a)
{
	int l = 0, r = my_strlen(a) - 1;
	char t;
	if(a == 0)
		return -1;
	while(l < r)
	{
		t = a[r];
		a[r] = a[l];
		a[l] = t;
		l++;
		r--;
	}
	return my_strlen(a);
}

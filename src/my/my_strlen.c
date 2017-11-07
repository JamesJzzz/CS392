/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"
int my_strlen(char* a)
{
	if (a == '\0')
	{

		return -1;
	}
	else
	{
		int l = 0;
		while (a[0] != '\0')
		{
			l++;
			a++;
		}
		return l;
	}
}

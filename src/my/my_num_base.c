/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"
#include <limits.h>

void my_num_base(int x, char* a)
{
	if(a != 0)
	{
		unsigned int divs = 1, b = my_strlen(a), y, z;
		z = 0;
		if(x < 0)
			my_char('-'); 
		y = x >= 0 ? x : (x == INT_MIN ? (unsigned int)INT_MAX + 1 : -x);
		if(b == 1)
		{
			for(z = 0; z < y; z++)
				my_char(a[0]);
		}
		else if(b >= 1)
		{
			while (y / divs >= b) divs *= b; 
			while (divs != 0) 
			{
				my_char(a[(y / divs)]); 
				y = y - (y / divs) * divs;
				divs = divs / b;
			}
		}
	}
}
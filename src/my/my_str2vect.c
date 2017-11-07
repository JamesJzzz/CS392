#include "my.h"

char **my_str2vect(char* a)
{
	char **ret;
	int x = 0, lAI = -1, retI = -1, m = 0, num = 0, *lA;
	char *e = "";
	if(a == NULL)
		return NULL;
	else if(a == e)
	{
		ret = (char **)malloc(sizeof(char *)*1);
		ret[0] = (char *)malloc(sizeof(char)*1);
		ret[0][0] = '\0';
		return ret;
	}
	while(a[x] != '\0') 
	{
		while(a[x] == ' ' && a[x] != '\0')
			x++;
			
		if(a[x] != '\0')
			num++;

		while(a[x] != ' ' && a[x] != '\0')
			x++;
	}
	lA = (int *)malloc(sizeof(int)*num); 
	for(x = 0; x < num; x++)
		lA[x] = 0;
	x = 0;
	while(a[x] != '\0') 
	{
		while(a[x] == ' ' && a[x] != '\0')
			x++;
			
		if(a[x] != '\0')
			lAI++;

		while(a[x] != ' ' && a[x] != '\0')
		{
			lA[lAI]++;
			x++;
		}
		lA[lAI]++; 
	}
	ret = (char **)malloc(sizeof(char *)*(num + 1)); 
	for(x = 0; x < num; x++)
		ret[x] = (char *)malloc(sizeof(char)*(lA[x] + 1));
	ret[x] = NULL;
	x = 0;
	while(a[x] != '\0') 
	{
		while(a[x] == ' ' && a[x] != '\0')
			x++;	
		if(a[x] != '\0')
			retI++;
		for(m = 0; m < lA[retI] - 1 && a[x] != '\0'; m++, x++) 
			ret[retI][m] = a[x];
		if(a[x] != '\0')
			ret[retI][m] = '\0';
	}
	free(lA);
	return ret;
}
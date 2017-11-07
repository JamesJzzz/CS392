#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t next_index = 0;
static unsigned char* thememory[1024*1024];

void * my_malloc(size_t size){
	void * memory;
	if(sizeof thememory - next_index < size){
		return NULL;
	}
	memory = &thememory[next_index];
	next_index = next_index + size;
	return memory;
}

int mian(){
   char *str;

   /* Initial memory allocation */
   str = (char *) my_malloc(15);
   strcpy(str, "lol");
   printf("String = %s,  Address = %u\n", str, str);
   
   return(0);
}

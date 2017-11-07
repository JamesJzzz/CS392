#include "my.h"
/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char* my_strconcat(char* a, char* b){
  char* dest;
  if(a==NULL){
    return NULL;}
  if(b==NULL){
    dest=(char*)malloc(my_strlen(a)+1);
    return my_strcpy(dest,a);
  }
  dest=(char*)malloc(my_strlen(a)+my_strlen(b)+1);
  my_strcpy(dest,a);
  return my_strcat(dest,b);
}

#include "my.h"

/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

char* my_strnconcat(char* dst,char* src, int n){
  char* dest;
  if (dst==NULL){
    return NULL;
  }
  if(src==NULL){
    dest=(char*)malloc(my_strlen(dst)+1);
    return my_strcpy(dest,dst);
  }
  dest=(char*)malloc(my_strlen(dst)+n+1);
  my_strcpy(dest,dst);
  return my_strncpy(dest+my_strlen(dst),src, n)-my_strlen(dst);
}

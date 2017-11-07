/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"
int my_strindex(char* s, char c)
{
  int i;
  for(i=0;i<=my_strlen(s);i++){
    if(s[i]==c){
      return i;
      break;
    }
  }
  return -1;
}
/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"
int my_strrindex(char* s, char c)
{
  int i;
  for(i=my_strlen(s)-1;i>=0;i--){
    if(s[i]==c){
      return i;
      break;
    }
  }
  return -1;
}

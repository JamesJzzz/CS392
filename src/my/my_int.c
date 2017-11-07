/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James Zhang
*/

#include "my.h"

void my_int(int num)
{
    int power = 1;
    int newNum;

    if(num < 0)
    {
        my_char('-');
        newNum = num * -1;
    }
    else
    {
        newNum = num;
    }
    
    while(power <= (newNum / 10))
        power *= 10;

    do
    {
        my_char('0' + (newNum / power));
        newNum %= power;
        power /= 10;
    } while(power);
    
}

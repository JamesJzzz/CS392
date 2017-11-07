/*

Zhiyuan(James) Zhang
Nov 3 2016
I pledge my honor that I have abided by the Stevens Honor System. ------James

Worked with Weizhe Dou, Meng Qiu.
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

int main(int argc, char** argv){
  int row;
  int col;
  int i;
  int len=0;
  int currow=0;
  int curcol=0;
  int ch;
  int underline=1;
  int* high;

  if(argc<=1){
		my_str("Usage:\n./myselect (files)\n");
		return 1;
	}
  initscr();
  noecho();
  raw();

  high=(int*)malloc(sizeof(int)*argc);

  for(i=0;i<argc;i++){
    high[i]=0;
  }

  while(1){
    currow=0;
    curcol=0;


    clear();
    getmaxyx(stdscr,row,col);
    for(i=1;i<=argc-1;i++){
      if (currow==row){
        curcol=len+1+curcol;
        len=0;
        currow=0;
      }

      if(my_strlen(argv[i])>len){
        len=my_strlen(argv[i]);
      }



      if(i==underline){
        attron(A_UNDERLINE);
      }
      if(high[i]%2==1){
        attron(A_STANDOUT);
      }
      else{
        attroff(A_STANDOUT);
      }
      mvprintw(currow,curcol,argv[i]);


      attroff(A_UNDERLINE);


      currow++;

      if(curcol+my_strlen(argv[i])>col){
        clear();
        mvprintw(0,0,"please enlarge the window");
        break;
      }

    }


    ch=getch();

    if(ch=='\n'){
      break;
    }

    if(ch==27){
      timeout(100);
      ch=getch();
      timeout(-1);
      if(ch==-1){
        endwin();
        return 0;
      }
      if(ch=='['){
        ch=getch();
        if (ch=='A') {
          if(underline!=1){
            underline-=1;
          }
          else{
            underline=argc-1;
          }
        }
        if (ch=='B') {
          if(underline!=argc-1){
            underline+=1;
          }
          else{
            underline=1;
          }
        }
        if (ch=='C') {
          if(!(underline+row>argc)){
            underline+=row;
          }
          else{
            underline=argc-1;
          }
        }
        if (ch=='D') {
          if(!(underline<row+1)){
            underline-=row;
          }
          else{
            underline=1;
          }
        }
      }
    }

    if(ch==' '){
      high[underline]+=1;
      if(high[underline]%2==1){
        if(underline!=argc-1){
          underline+=1;
        }
        else{
          underline=1;
        }
      }
    }
  }

  endwin();
  for(i=0;i<argc;i++){
    if(high[i]%2==1){
      my_str(argv[i]);
      my_char(' ');
    }
  }
  my_char('\n');

  return 0;
}

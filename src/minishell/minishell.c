#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

pid_t pid;

void controlc(int sig){
  if(sig==SIGINT){
    if(pid>0){
      kill(pid,SIGKILL);
    }
  }
}

int main(){
  char cwd[1000];
  char inp[1000];
  int n;
  char** vec;

  signal(SIGINT,controlc);



  while(1){
    getcwd(cwd,1000);
    my_str("MINISHELL: ");
    my_str(cwd);
    my_str(" $: ");

    n=read(0,inp,1000);
    if(n<0){
      my_str("Reading Error\n");
      return 1;
    }
    inp[n-1]='\0';
    vec=my_str2vect(inp);

    if(!my_strcmp(vec[0],"cd")){
      n=chdir(vec[1]);
      if(n<0){
        my_str("Changing directory Error\n");
      }
    }

    else if(!my_strcmp(vec[0],"help")){
      my_str("cd: change current directory.\nhelp: showing all the command with their functions.\nexit: exit the program\n");
    }

    else if(!my_strcmp(vec[0],"exit")){
      return 0;
    }

    else{
      pid=fork();

      if(pid<0){
    		/*error*/
    		my_str("Error\n");
    		return 1;
    	}
      else if(pid==0){
    		/*child*/
        n=execvp(vec[0],vec);
        if(n<0){
          my_str("Execvp Error\n");
          exit(0);
        }
      }
      else{
        wait(0);
        pid=0;
      }
    }
  }
}

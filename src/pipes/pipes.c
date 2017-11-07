/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the
Stevens Honor System. ------James
*/

#include "my.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]){
	int pipelol1[2];
	int pipelol2[2];
	int status;
	char *input = my_vect2str(&argv[1]);
	char *readin = (char *)malloc(sizeof(char) * 1024);
	pid_t pid1;
	pid_t pid2;

	if (argc <= 1){
		my_str("There is no command line arguments given.\n");
		return 0;
	}
	if (pipe(pipelol1)<0){
		my_str("The first pipe is failed to create.\n");
		exit(1);
	}
	pid1 = fork();
	if(pid1 > 0){
		close(pipelol1[0]);
		my_str("Parent ");
		my_int(getpid());
		my_str(": ");
		my_str(input);
		my_char('\n');
		write(pipelol1[1], input, 1024);
		wait(&status);
	}
	else if(pid1<0){
		my_str("First fork failed.\n");
		free(readin);
		exit(1);
	}
	else{
		close(pipelol1[1]);
		read(pipelol1[0],readin,1024);
		if (pipe(pipelol2)<0){
			my_str("The second pipe is failed to create.\n");
			free(readin);
			exit(1);
		}
		pid2 = fork();
		if(pid2 > 0){
			close(pipelol2[0]);
			my_str("Child ");
			my_int(getpid());
			my_str(": ");
			my_str(readin);
			my_char('\n');
			write(pipelol2[1],readin,1024);
			wait(&status);
			free(readin);
			return 0;
		}
		else if(pid2< 0){
			my_str("Second fork failed.\n");
			free(readin);
			exit(1);
		}
		else{
			close(pipelol2[1]);
			free(readin);
			readin = (char *)malloc(sizeof(char) * 1024);
			read(pipelol2[0], readin,1024);
			my_str("Grandchild ");
			my_int(getpid());
			my_str(": ");
			my_str(readin);
			my_str("\n\n");
			free(readin);
			return 0;
		}
	}
	free(readin);
	return 0;
}
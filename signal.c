#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


void childprocess(void){
	printf("Signal Recieved!\n");
	pause();
	printf("Child existing...\n");
	pause();

}

void parentprocess(void){

	pause();
}

int main(){
	pid_t pid;
	pid = fork();

	if (pid < 0 ){

	}
	else if (pid ==0){
		childprocess();
	}
	else if (pid>0){
		parentprocess();
	}

}

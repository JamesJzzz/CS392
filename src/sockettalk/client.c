/*
Zhiyuan(James) Zhang
I pledge my honor that I have abided by the 
Stevens Honor System. ------James

Cited some codes from 
https://www.tutorialspoint.com/index.htm

had a problem with connection issues,
error message was connection refused. never seen that before.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include "my.h"

int main(int argc, char *argv[]) {
   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;
   fd_set readlol;
   
   char buffer[256];
   
   if (argc != 3) {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
   my_str("Enter the username: ");

   n = read(STDIN_FILENO, buffer, 255);
	if (n < 0) {
		perror("Error reading from stdin");
		exit(0);
	}
	buffer[n] = '\0';

  	portno = my_atoi(argv[2]);
   	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("Error opening socket");
		exit(0);
	}
	server = gethostbyname(argv[1]);
	if (server == NULL) {
		perror("Can't find host");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		perror("Error connecting");
		exit(0);
	}
	n = write(sockfd, buffer, my_strlen(buffer));
	if(n<0){
		perror("Error writing to socket");
		exit(0);
	}
	bzero(buffer, 256);
	n = read(sockfd, buffer, 255);
	if (n < 0) {
		perror("Error reading from socket");
		exit(0);
	}
	my_str(buffer);
	my_char('\n');
	
	while(1) {
		FD_ZERO(&readlol);
		FD_SET(sockfd, &readlol);
		FD_SET(0, &readlol);
		
		if (select(sockfd + 1, &readlol, NULL, NULL, NULL) < 0) {
			perror("Select Error");
			exit(0);
		}
		
		if (FD_ISSET(sockfd, &readlol)) {
			bzero(buffer, 256);
			n = read(sockfd, buffer, 255);
			if (n < 0) {
				perror("Error reading from socket\n");
				exit(0);
			}
			my_str(buffer);
			my_char('\n');
		} else if (FD_ISSET(0, &readlol)) {
		
			bzero(buffer, 256);
			fgets(buffer, 255, stdin);
			n = write(sockfd, buffer, my_strlen(buffer));
			if (n < 0) {
				perror("Error writing to socket\n");
				exit(0);
			}
			if (my_strcmp(buffer, "/exit\n") == 0) {
				close(sockfd);
				exit(0);
			}
		}
		
	}
	close(sockfd);
	return 0;
}






















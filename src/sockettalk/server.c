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
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include "my.h"
#include <netdb.h>

int main(int argc, char *argv[]){
	int sockfd;
	int newsockfd,portno;
	int client_socket[40],max_clients = 40;
	int socketd, max_socketd;
	int i,n;
	char buffer[256];
	char* usernames[1024];
	char** slash;
	struct sockaddr_in serv_addr;
	socklen_t addrlen;
	fd_set readfds;

	if (argc != 2){
		perror("Usage: ./server [port]");
		exit(0);
	}

	for (i = 0; i < max_clients; i++){
		client_socket[i] = 0;
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("ERROR opening socket");
		exit(0);
	}

	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = my_atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		my_str("Error on binding\n");
		exit(0);
	}

	if (listen(sockfd, 5) < 0) {
		perror("listen failed");
		exit(0);
	}

	addrlen = (socklen_t)sizeof(serv_addr);
	while(1) {
		FD_ZERO(&readfds);
		FD_SET(sockfd, &readfds);
		max_socketd = sockfd;
		
		for (i = 0; i < max_clients; i++) {
			socketd = client_socket[i];
			
			if (socketd > 0) {
				FD_SET(socketd, &readfds);
			}
			
			if (socketd > max_socketd) {
				max_socketd = socketd;
			}
		}
		if (select(max_socketd + 1, &readfds, NULL, NULL, NULL) < 0) {
			close(sockfd);
			exit(0);
		}
		if (FD_ISSET(sockfd, &readfds)) {
			newsockfd = accept(sockfd, (struct sockaddr *)&serv_addr, &addrlen);
			if (newsockfd < 0) {
      		perror("ERROR on accept");
      		exit(0);
      	}

      	bzero(buffer,256);
   		n = read( newsockfd,buffer,255 );
   
   		if (n < 0) {
      		perror("ERROR reading from socket");
      		exit(1);
   		}
   		printf("Here is the message: %s\n",buffer);

   		n = write(newsockfd,"Welcome", 7);
   
   		if (n < 0) {
      		perror("ERROR writing to socket");
      		exit(0);
   		}
   		for (n = 0; n < max_clients; n++) {
				if (client_socket[n] == 0) {
					client_socket[n] = newsockfd;
					break;
				}
			}	
		}

		for ( i = 0; i <= max_socketd; i++){
			socketd = client_socket[i];
			if (FD_ISSET(socketd, &readfds)){
				bzero(buffer, 256);
				n = read(socketd,buffer,255);
				if(n<0){
					perror("ERROR reading from the socket");
					exit(0);
				}
				buffer[n] = '\0';
				if(buffer[n-1] == '\n'){
					buffer[n-1] = '\0';
				}
				if(buffer[0] == '/'){
					slash = my_str2vect(buffer);
					if (my_strcmp(slash[0], "/me") == 0) {
						if (usernames[socketd][my_strlen(usernames[socketd]) - 1] == '\n') {
							usernames[socketd][my_strlen(usernames[socketd]) - 1] = '\0';
						}
						for (n = 0; n < max_clients; n++) {
							if((client_socket[n] != 0) && (client_socket[n] != sockfd)) {
								if (write(client_socket[n], usernames[socketd], my_strlen(usernames[socketd])) < 0) {
									perror("Error writing to socket");
									exit(0);
								}
								if (write(client_socket[n], " ", 1) < 0) {
									perror("Error writing to socket");
									exit(0);
								}
								if (write(client_socket[n], &buffer[4], my_strlen(&buffer[4])) < 0) {
									perror("Error writing to socket");
									exit(0);
								}
							}
						}
					}
					else if (my_strcmp(slash[0], "/nick") == 0) {
						free(usernames[socketd]);
						usernames[socketd] = strdup(&buffer[6]);
						if (write(socketd, "Name changed to: ", 17) < 0) {
							perror("Error writing to socket");
						}
						if (write(socketd, usernames[socketd], my_strlen(usernames[socketd])) < 0) {
							perror("Error writing to socket");
						}
					}
					else if(my_strcmp(slash[0], "/exist") == 0){
						close(socketd);
						free(usernames[socketd]);
						for(n = 0; n<max_clients;n++){
							if (client_socket[n] == socketd){
								client_socket[n] = 0;
								break;
							}
						}
					}
					else{
						if (write(socketd, "Invalid Command", 15) < 0) {
							perror("Error writing to socket");
							exit(0);
						}
					}
				}
				else{
					if (usernames[socketd][my_strlen(usernames[socketd]) - 1] == '\n') {
						usernames[socketd][my_strlen(usernames[socketd]) - 1] = '\0';
					}
					for(n = 0; n<max_clients; n++){
						if((client_socket[n] != 0)&&(client_socket[n] != socketd)){
							if(write(client_socket[n],usernames[socketd],my_strlen(usernames[socketd]))<0){
								perror("Error writing to socket");
								exit(0);
							}
							if (write(client_socket[n], ": ", 2) < 0) {
								my_str("Error writing to socket\n");
								exit(0);
							}
							if (write(client_socket[n], buffer, my_strlen(buffer)) < 0) {
								my_str("Error writing to socket\n");
								exit(0);
							}
						}
					}
				}
			}
		}
	}
	close(sockfd);
	return 0;
}













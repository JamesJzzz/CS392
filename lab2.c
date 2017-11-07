#include <unisted.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv){
	int encrypted = open ("encrypted.txt", 0_RDONLY);
	int solution = open ("solution.txt", 0_WRONLY);

	int i;
	int message[44];
	if (read(encrypted, msg, 44) < 0) {
		return 1;
	}
	for (i = 0; i < 44; i++){
		if (message[i] != ' ' && message[i] != '!'){
			if (message[i] >= 97){
				message[i] = ((((message[i] - 97)- (5 + (2 * (i/ 3 ))))+26) % 26) +97;
			}
			else {
				message[i] = ((((message[i] - 65) - (5 + (2 * (i / 3))))+ 26) % 26 ) +97;
			}
		}
	}
	write(solution, message, 44);
	return 0;
}
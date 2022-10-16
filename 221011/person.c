#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("ERROR\n");
		return 0;
	}

	int num = atoi(argv[1]);
	int cmd;

	while(1){
		printf("INPUT >> ");
		scanf("%d", &cmd);
		switch(cmd){
			case 1 :
				kill(num, SIGUSR1);
				break;
			case 2 :
				kill(num, SIGUSR2);
				break;
			case 3 :
				kill(num, SIGTERM);
				break;
		}
	}
}


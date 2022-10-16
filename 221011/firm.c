#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void run1(){
	printf("[Button clicked]\n");
}

void run2(){
	system("clear");
	printf("RESET\n");
}

void run3(){
	printf("BYE~\n");
	exit(0);
}

int main(){
	setbuf(stdout,NULL);

	signal(SIGUSR1,run1);
	signal(SIGUSR2,run2);
	signal(SIGTERM,run3);

	while(1){
		for(char ch = 'A'; ch<='Z'; ch++){
			printf("%c\n",ch);
			usleep(100000);
		}
		for(char ch = 'Z'; ch>='A'; ch--){
			printf("%c\n",ch);
			usleep(100000);
		}
	}
	return 0;
}

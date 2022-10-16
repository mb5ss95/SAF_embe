/*
 ============================================================================
 Name        : 220930_embe4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char DATA[300][30];

// 데이터 전체 읽어 오기 (file read)
void readAll(){
	FILE *fp = fopen("./nand.txt", "r");
	int index = 0;
    while (!feof(fp)) {
    	char buffer[30];
    	//fread(buffer, sizeof(buffer), 1, fp);
    	fgets(buffer, sizeof(buffer), fp);
    	if(buffer[strlen(buffer) - 1] == '\n') buffer[strlen(buffer) - 1] = 0;
        strcpy(DATA[index++], buffer);
    }
    fclose(fp);
}

// 데이터 읽어 오기 (file read가 아니고 DATA 배열에서 가져옴)
char* readDATA(uint8_t address){
	if(!strcmp(DATA[address], "\n") || strlen(DATA[address]) == 0) return "EMPTY\n";
	if(DATA[address][strlen(DATA[address]) - 1] == '\n') return DATA[address];
	strcat(DATA[address], "\n");
	return DATA[address];
}

// 전체 저장 (file write)
void writeAll(){
	FILE *fp = fopen("./nand.txt", "w");
	for(int i = 0; i < 100; i++){
		if(!strcmp(DATA[i], "\n") || strlen(DATA[i]) == 0) {
			fwrite("\n", 1, 1, fp);
			continue;
		}
		fputs(DATA[i], fp);
		fputs("\n", fp);
	}
    fclose(fp);
}

// 데이터 저장 (DATA 배열에서 값을 바꾸고 file Write를 함)
void writeDATA(uint8_t address, char command[10]){
	strcpy(DATA[address], command);
	writeAll();
}

// 명령어 실행
char* startCommand(char command[3][10]){
	if(!strcmp(command[0], "R") && strcmp(command[1], "NONE")){
		uint8_t address = atoi(command[1]);
		char *result = readDATA(address);
		return result;
	}
	else if(!strcmp(command[0], "W") && strcmp(command[1], "NONE")){
		uint8_t address = atoi(command[1]);
		writeDATA(address, command[2]);
		return "SUCCESS\n";
	}
	else if(!strcmp(command[0], "exit")){
		printf("GOOD BYE!\n");
		exit(0);
	}
	else if(!strcmp(command[0], "help")){
		printf("R index \n-> print value\n");
		printf("W index value\n-> write value\n");
		printf("fullwrite value\n-> write all\n");
		printf("fullread \n-> print all\n");
		printf("exit \n-> exit program\n");
		return "";
	}
	else if(!strcmp(command[0], "fullwrite")){
		for(int i = 0; i < 100; i ++){
			strcpy(DATA[i], command[1]);
		}
		writeAll();
		return "SUCCESS\n";
	}
	else if(!strcmp(command[0], "fullread")){
		for(int i = 0; i < 100; i ++){
			if(!strcmp(DATA[i], "\n") || strlen(DATA[i]) == 0) continue;
			printf("%d -> %s\n", i, DATA[i]);
		}
		return "";
	}
	else{
		return "COMMAND ERROR\n";
	}
}

int main(void) {
	readAll(DATA); // 프로그램 시작시 전체 데이터를 가져와 DATA배열에 담아둠

	while(1){
		char command[3][10] = {
				"NONE",
				"NONE",
				"NONE"
		};
		char msg[30];

		printf("ssd >> ");
		gets(msg);

		// 명령어 나누기
		sscanf(msg, "%s %s %s", command[0], command[1], command[2]);
		char *result = startCommand(command);
		printf("%s", result);
	}

	return 0;
}

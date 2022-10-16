/*
 * dj.h
 *
 *  Created on: 2022. 9. 27.
 *      Author: multicampus
 */

#ifndef DJ_H_
#define DJ_H_

void dj_run(){
	typedef unsigned char uc;

	char A[] = "0xFF";
	char B[] = "00000000";

	uc a = strtol(A, NULL, 16);
	uc b = strtol(B, NULL, 2);

	uc result1 = ~(a&b)<<4;
	uc result2 = (a^0xcd) & (b>>3);

	printf("%x\n", result1);
	printf("%x\n", result2);
}

void dj_run2(){

	char op[][4] = {"?", "~", "&", "|", "^", "<<", ">>"};

	//http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2583
	printf("%s\n",     op[2]);               /// (1)
	printf("%s%s\n",   op[1], op[2]);        /// (2)
	printf("%s\n",     op[5]);               /// (3)
	printf("%s%s%s\n", op[6], op[2], op[5]); /// (4)
	printf("%s%s%s\n", op[4], op[4], op[4]); /// (5)
	printf("%s%s\n",   op[6], op[2]);        /// (6)
	printf("%s%s%s\n", op[2], op[1], op[5]); /// (7)
	printf("%s%s\n",   op[4], op[5]);        /// (8)
	printf("%s\n",     op[2]);               /// (9)
	printf("%s%s\n",   op[4], op[2]);        /// (10)

}

void dj_run3(){

	const char *p[3] = {
			"[000053.163123] MIN CO MIN CO MIN CO",
			"[004351.231231] EMBEDDED EM EM EM",
			"[123456.654321] HO HO HO KKK",
	};

	for(int i = 0; i < 3; i++){
		char result[50];
		char msg[50];
		float time;

		sscanf(p[i], "[%f] %[^\n]", &time, msg);
		sprintf(result, "[%.f] sec :  %s", time, msg);
		printf("%s\n", result);
	}
}

int isNum(char* str)
{
	for (int i = 0; str[i]; i++) {
		if (!(str[i] >= '0' && str[i] <= '9')) return 0;
	}
	return 1;
}

void dj_run4(){
	const char* vect = "DATA|32ALL|0|200|100|ABABC|200";
	char str[100];
	char result[100] = { 0 };

	int sum = 0;
	const char* div = "|";
	strcpy(str, vect);

	for (char* p = strtok(str, "|"); p != NULL; p = strtok(NULL, "|")) {
		if (isNum(p) == 0 && strcmp("0", p)) {
			//문자열
			strcat(result, p);
			strcat(result, "|");
		}
		else {
			//숫자
			sum += atoi(p);
		}
	}

	int n = strlen(result);
	result[n - 1] = '\0';

	printf("sum : %d\n", sum);
	printf("other : %s\n", result);
}

void dj_run5(){
	char vect[100] = "DBABCEQABC";
	char tar[4] = "ABC";

	int tn = strlen(tar);

	while (1)
	{
		char* p = strstr(vect, tar);
		if (p == NULL) break;
		printf("%s\n", vect);
		printf("%s\n", p);
		strcpy(p, p + tn);
	}

	printf("%s", vect);
}

void dj_pjt(){
	FILE *fp = fopen("input.txt", "r");

	typedef struct Node {
		char key[30];
		int startIdx;
		int cnt;
	}N;

	int while_cnt = 0;
	char map[3000][300];
	char buf[300];
	char result[30];
	char month[20];
	char time[20];
	char td[20];

	N node[1000];
	int n_idx = 0;
	while (!feof(fp)) {
		fgets(buf, 300, fp);

		sscanf(buf, "%s %s %s", month, td, time);
		sprintf(result, "%s %s %s", month, td, time);
		strcpy(map[while_cnt], buf);

		//이전거랑 현재거랑 같으면
		if (strcmp(node[n_idx].key, result) == 0) {
			node[n_idx].cnt++;
		}
		else {//다르면
			n_idx++;
			strcpy(node[n_idx].key, result);
			node[n_idx].startIdx = while_cnt;
			node[n_idx].cnt = 1;
		}

		while_cnt++;
	}

	fclose(fp);
	n_idx++;//마지막으로 추가한 node의 인덱스가 n_idx이므로, node의 개수= idx+1이다.

//	printf("=====================\n");//node는 어떻게 생겨먹었나? 확인
//	for (int i = 0; i < n_idx; i++) {
//		printf("node[%03d].key:%s, cnt:%d\n", i, node[i].key, node[i].cnt);
//	}
//	printf("n_idx=%d\n", n_idx);//n_idx = 625개


	for (int i = 0; i < n_idx; i++) {
		for (int j = i + 1; j < n_idx; j++) {
			if (node[i].cnt < node[j].cnt) {
				char tmp_key[30];
				int tmp_cnt;
				int tmp_idx;
				strcpy(tmp_key, node[i].key);
				tmp_cnt = node[i].cnt;
				tmp_idx = node[i].startIdx;

				strcpy(node[i].key, node[j].key);
				node[i].cnt = node[j].cnt;
				node[i].startIdx = node[j].startIdx;

				strcpy(node[j].key, tmp_key);
				node[j].cnt = tmp_cnt;
				node[j].startIdx = tmp_idx;
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		printf("=====================\n");
		printf("node[%02d].key:%s, cnt:%d\n", i, node[i].key, node[i].cnt);
		printf("=====================\n");
		for (int j = node[i].startIdx; j < node[i].cnt + node[i].startIdx; j++) {
			printf("%s", map[j]);
		}

	}
	//36, 32, 28
}

#endif /* DJ_H_ */

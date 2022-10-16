/*
 * main.h
 *
 *  Created on: 2022. 9. 28.
 *      Author: multicampus
 */

#ifndef MAIN_H_
#define MAIN_H_

// struct
void run1(){
	struct Node{
		int a;
		int b;
	};

	// typedef struct
	typedef struct Node n;
	n a = {1, 2};
	n b = {3, 4};
	printf("%d %d", a.a, b.b);

	// struct
	struct Node node;
	node.a = 3;
	node.b = 5;
	printf("%d %d", node.a, node.b);
}

// Union
void run2(){
	// 유니온은 맴버들끼리 값을 공유한다
	// 바이트 단위의 파싱을 편리하게 할수 있음
	typedef union _ABC_{
		uint32_t a;
		uint8_t b[4];
	}abc;

	abc data;
	data.a = 0x1234ABCD;
	//data.b[0] = 0xcd;
	//data.b[1] = 0xab;
	//data.b[2] = 0x34;
	//data.b[3] = 0x12;
}

// struct in struct
void run3(){
	struct Node{
		int a;

		struct {
			int b1;
			int b2;
		}b;

		int c;
	};

	struct Node v;

	v.a = 20;
	v.b.b1 = 50;
	v.b.b2 = 30;
	v.c = 10;
}

// struct 선택적 초기화
void run4(){
	struct Node{
		int a;

		struct {
			int b1;
			int b2;
		}b;

		int c;
	};

	struct Node v = {
			.a = 10,
			// 중간을 비워도 됨
			.c = 30
	};

	printf("%d %d %d", v.a, v.b.b1, v.c);
}

void run5(){
	typedef struct _NODE_{
		union {
			int b1;
			int b2;
		}b;
		int c;
	}Node;

	Node node = {{5}, 7}; // 5 5 7
}


#endif /* MAIN_H_ */

/*
 * parse.h
 *
 *  Created on: 2022. 9. 28.
 *      Author: multicampus
 */

#ifndef PARSE_H_
#define PARSE_H_

// union을 사용하면 간단하게 파싱 가능
void run1(){
	uint8_t target[7] = {0xAB, 0x12, 0x13, 0xFA, 0xAA, 0xFF, 0xA0};

	union _NODE_{
		uint8_t receiveData[7];

		struct {
			uint8_t head;
			uint8_t body[5];
			uint8_t tail;
		}msg;
	}node;

	memcpy(node.receiveData, target, 7);

	printf("head = %02x\n", node.msg.head);
	printf("body = ");
	for(int i = 0; i < 5; i++){
		printf("%02x ", node.msg.body[i]);
	}
	printf("\n");
	printf("tail = %02x\n", node.msg.tail);
}

void run2(){
// 해당 코드 밑으로 모든 구조체는 패딩을 사용하지 않음
#pragma pack(1)
	struct Node1{
		char a;
		int t;
	};

// 원상 복구
#pragma pack(4)
	struct Node2{
		char a;
		int t;
	};

	printf("%d\n", sizeof(struct Node1)); // 5
	printf("%d\n", sizeof(struct Node2)); // 8
}

void run3(){
#pragma pack(1)
	union node{
		uint8_t compa;
		struct {
			uint8_t a : 1;
			uint8_t b : 1;
			uint8_t c : 5;
			uint8_t d : 1;
		}msg;
	}uni;

	uni.compa = 0x73; // 0b 0111 0011
	printf("%x\n", uni.compa);
	printf("%x\n", uni.msg.a); // 1
	printf("%x\n", uni.msg.b); // 1
	printf("%x\n", uni.msg.c); // 1c
	printf("%x\n", uni.msg.d); // 0
}

void run4(){
#pragma pack(1)
	struct {
		uint8_t a : 1;
		uint8_t b : 1;
		uint8_t c : 5;
		uint8_t d : 1;
	}msg;

	uint8_t data = 0x73; // 0b 0111 0011
	memcpy(&msg, &data, sizeof(data));
	printf("%x\n", msg.a); // 1
	printf("%x\n", msg.b); // 1
	printf("%x\n", msg.c); // 1c
	printf("%x\n", msg.d); // 0
}

void run5(){
#pragma pack(1)
	struct {
		uint16_t a : 3;
		uint16_t b : 3;
		uint16_t c : 4;
		uint16_t d : 6;
	}msg;

	uint16_t data = 0xF3B5; // 0b 1111 0011 1011 0101
	memcpy(&msg, &data, sizeof(data));
	printf("%X\n", data); // F3B5
	printf("%X\n", msg.a); // 5
	printf("%X\n", msg.b); // 6
	printf("%X\n", msg.c); // E
	printf("%X\n", msg.d); // 3C
}

void run6(){
	uint8_t buf[] = {0x08, 0xF2, 0x34, 0x56, 0x20, 0x1C};

#pragma pack(1)

	struct {
		uint8_t opcode;

		uint8_t lba_part1 : 5;
		uint8_t reserved : 3;

		uint8_t lba_part2;
		uint8_t lba_part3;

		uint8_t length;
		uint8_t control;
	}field;


	memcpy(&field, buf, 6);

	printf("%02X\n", field.opcode);
	printf("%02X\n", field.reserved);
	printf("%02X\n", field.lba_part1);
	printf("%02X\n", field.lba_part2);
	printf("%02X\n", field.lba_part3);
	printf("%02X\n", field.length);
	printf("%02X\n", field.control);
}

#endif /* PARSE_H_ */

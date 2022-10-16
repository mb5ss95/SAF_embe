/*
 * bit1.h
 *
 *  Created on: 2022. 9. 27.
 *      Author: multicampus
 */

#ifndef BIT_H_
#define BIT_H_

void run1(){
	typedef unsigned char uc;
	uc a = 0xc0;

	// clear
	uc clearA = a & ~(0x1<<7);

	// set
	uc setA = a | (0x1<<0);

	// toggle

	uc toggleA = a ^ (0x1<<2);

	printf("%x\n", clearA);
	printf("%x\n", setA);
	printf("%x\n", toggleA);
}

void run2(){

	char input1[] = "0x00010001";
	char input2[] = "00010001";

	// HexaDecimal to Decimal
	int hex = strtol(input1, NULL, 16);

	// binary to Decimal
	int bin = strtol(input2, NULL, 2);

	printf("%d\n", hex);
	printf("%d\n", bin);

	// sprintf
	int a = 108; // 0x6C
	char buffer[10];

	sprintf(buffer, "%X", a);
	printf("%s\n", buffer);
}

void run3(){
	// Decimal to binary
	int a = 17;
	char buf[10] = { 0, };
	int bn = 0;

	for(int i = a; i != 0; i /= 2){
		buf[bn++] = (i % 2) + '0';
	}

	printf("%s\n", buf);
}

#endif /* BIT_H_ */

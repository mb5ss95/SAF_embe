#include <stdio.h>



int main() {
	typedef unsigned char uc;
	uc a = 0b11000111;
	uc a0set = 0b00000001;
	uc a3set = 0b00000100;
	uc a5set = 0b00010000;

	printf("%x\n", a);
	printf("%x\n", a & (~0x0E));
	return 0;
}


/*
 ============================================================================
 Name        : test1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _a_ {
	int a;
	int b;
}a;

struct _b_ {
	int a;
	int b;
}b;

int main(void) {
	a c = { 1, 2 };
	b = { 3, 4 };
	return EXIT_SUCCESS;
}

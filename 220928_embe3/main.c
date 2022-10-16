#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {

#pragma pack(1)
	union _uni_{
		uint8_t buf[14];
		struct{
			uint8_t weigth[2];
			uint8_t uID[2];
			uint8_t money[2];
			uint8_t food[4];
			uint8_t drink[4];
		}msg;
	}uni;

	uint8_t buf[] = { 0x00, 0x58, 0x0a, 0x0c, 0xe8, 0xfd, 0x49, 0x47, 0x4f, 0x47, 0x49, 0x50, 0x4f, 0x43};
	memcpy(uni.buf, buf, sizeof(buf));

	uint16_t weigth = uni.msg.weigth[1] | (uni.msg.weigth[0] << 4);
    uint16_t pass = uni.msg.uID[1] | (uni.msg.uID[0] << 4);
    uint16_t money = uni.msg.money[1] | (uni.msg.money[0] << 4);

    printf("%d\n", weigth);            // 88kg
    printf("%d\n", pass);               // 3082
    printf("%d\n", money);  // 65000
    for(int i  = 3 ; i >= 0; i--) printf("%c", uni.msg.food[i]);
    printf("\n");
    for(int i  = 3 ; i >= 0; i--) printf("%c", uni.msg.drink[i]);

	return 0;
};

/*
 * dj.h
 *
 *  Created on: 2022. 9. 28.
 *      Author: multicampus
 */

#ifndef DJ_H_
#define DJ_H_

void run(){
    FILE *fp = fopen("binary", "rb");
    uint8_t buf[14];
    fread(buf, 1, 14, fp);
    fclose(fp);

    for(int i = 0; i < 14; i++){
    	printf("%x\n", buf[i]);
    }
    return;
}

#endif /* DJ_H_ */

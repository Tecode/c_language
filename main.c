//
// Created by Aming on 2021/10/25.
//

#include "stdio.h"
#include "stdlib.h"

unsigned char *numberToBitList(unsigned char number) {
    unsigned char *bitList = malloc(sizeof(unsigned char) * 3);
    unsigned char binary[3] = {0,0,0};
    unsigned char i = 0;
    while (number > 0) {
        binary[i] = number & 1;
        number >>= 1;
        i++;
    }
    bitList[0] = binary[2];
    bitList[1] = binary[1];
    bitList[2] = binary[0];
    printf("%d-%d-%d \n", binary[2], binary[1], binary[0]);
    return bitList;
}

int main() {
    printf("%X \n", (unsigned char )~0xF0);
    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of short: %zu bytes\n", sizeof(short));
    printf("Size of long: %zu bytes\n", sizeof(long));
    return 0;
}
//
// Created by Aming on 2021/10/25.
//

#include "stdio.h"

unsigned char *numberToBitList(unsigned char number) {
    unsigned char bitList[3] = {0, 0, 0};
    bitList[2] = (number - 1) % 2;
    bitList[1] = (number - 2) % 2;
    bitList[0] = (number - 4) / 2;
    return bitList;
}

int main() {
    unsigned char *ptr = numberToBitList(6);
    printf("%d-%d-%d", ptr[0], ptr[1], ptr[2]);
}
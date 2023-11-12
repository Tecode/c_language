//
// Created by 徐洁 on 2023/11/11.
//
// 点位图
#include "stdio.h"

void drawMatrix(char data) {
//    横向取模
    unsigned char list[] = {0x7E,0xE7,0xA5,0x99,0x99,0x81,0x66,0x3C};
    for (char column = 0; column < 8; ++column) {
        if (column > 0) {
            printf("\n");
        }
        unsigned char value = list[column];
        for (char index = 0; index < 8; ++index) {
            printf(" %C ", (value & (0x80 >> index)) ? '0': ' ');
        }
    }
}

int main() {
    drawMatrix(0x42);
    return 1;
}
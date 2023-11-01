//
// Created by 昊轩 on 2023/10/31.
//

#include "mcs51/8052.h"
#include "common.h"
#include "stdlib.h"


// 静态数码管显示，输入数字是多少显示多少 1-8
void staticDisplay(unsigned char number) {
    unsigned char light[8] = {0x30, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F};
    unsigned char bitList[3] = {0, 0, 0};
    unsigned char i = 0;
    P0 = light[number - 1];
//    for (unsigned char index = 0; index < 3; index++) {
//        bitList[index] = number & 1;
//        number >>= 1;
//        i++;
//    }
//    P2_4 = bitList[2];
//    P2_3 = bitList[1];
//    P2_2 = bitList[0];
//    while (number > 0) {
//        bitList[i] = number & 1;
//        number >>= 1;
//        i++;
//    }
    switch (number) {
        case 1: // NOLINT(*-branch-clone)
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 2:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 3:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 4:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 0;
            break;
        case 5:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 6:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 7:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 8:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 0;
            break;
        default:
            break;
    }
}

// 数字从1-8，1秒变一次
void loopLight() {
    for (unsigned char index = 1; index < 9; index++) {
        setTimeOut(1000);
        staticDisplay(index);
    }
}


// 显示1234
void numberLight() {
    staticDisplay(1);
    setTimeOut(1);
    P0 = 0x00;
    staticDisplay(2);
    setTimeOut(1);
    P0 = 0x00;
    staticDisplay(3);
    setTimeOut(1);
    P0 = 0x00;
    staticDisplay(4);
    setTimeOut(1);
    P0 = 0x00;
}
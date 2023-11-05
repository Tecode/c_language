//
// Created by 徐洁 on 2023/10/28.
//
#include "mcs51/8052.h"
#include "common.h"

// 闪烁的小灯
void blinkLight() {
    setTimeOut(1000);
    P2 = 0xFE;
    setTimeOut(1000);
    P2 = 0x00;
}

// 流水灯（基于寄存器地址P2）
void waterLamps() {
    P2 = 0x7F;              // 0111 1111 127
    setTimeOut(1000);
    P2 = 0xBF;              // 1011 1111 191
    setTimeOut(1000);
    P2 = 0xDF;              // 1101 1111 223
    setTimeOut(1000);
    P2 = 0xEF;              // 1110 1111 239
    setTimeOut(1000);
    P2 = 0xF7;              // 1111 0111 247
    setTimeOut(1000);
    P2 = 0xFB;              // 1111 1011 251
    setTimeOut(1000);
    P2 = 0xFD;              // 1111 1101 253
    setTimeOut(1000);
    P2 = 0xFE;              // 1111 1110 254
    setTimeOut(1000);
}

// 按下灯亮，松开熄灭
void buttonControlLight01() {
    while (1) {
        if (P3_1 == 0) {
            P2_0 = 0;
        }
        if (P3_1 == 1) {
            P2_0 = 1;
        }
    }
}

// 按下灯亮，再按下熄灭
void buttonControlLight02() {
    while (1) {
        if (P3_1 == 0) {
            setTimeOut(20);
            while (P3_1 == 0);
            setTimeOut(20);
            P2_0 = 1 ^ P2_0;
        }
    }
}

// k0按一次灯亮一个，依次循环 k2关闭所有小灯 k3跑马灯
void buttonControlLight03() {
    unsigned char count = 0;
    unsigned char loop = 0;
    unsigned reduce = 0;
    while (1) {
        if (P3_1 == 0) {
            setTimeOut(20);
            while (P3_1 == 0);
            setTimeOut(20);
            P2 = P2 << 1;
            loop = 0;
        }
        if (P3_0 == 0) {
            setTimeOut(20);
            while (P3_0 == 0);
            setTimeOut(20);
            P2 = 0xFF;
            loop = 0;
        }
        // 跑马灯
        if (P3_2 == 0) {
            setTimeOut(20);
            while (P3_2 == 0);
            setTimeOut(20);
            loop = 1;
        }

        if (loop) {
            setTimeOut(500);
            if (count == 6) {
                reduce = 1;
            }
            if (count == 0) {
                reduce = 0;
            }
            if (reduce) {
                count--;
                P2 = P2 >> 1;
            } else {
                count++;
                P2 = P2 << 1;
            }
        }
    }
}

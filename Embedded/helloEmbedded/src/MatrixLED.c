//
// Created by 徐洁 on 2023/11/7.
//

#include "MatrixLED.h"
#include "mcs51/8052.h"

__sbit __at (0xB4) SER ; // SER
__sbit __at (0xB5) RCK ; // RCLK
__sbit __at (0xB6) SRK ; // SERCLK

void WriteByteTo74HC595(unsigned char Byte) {
    // 先把最高位取出，依次位移时
    // 1000 0000 0x80
    for (int index = 0; index < 7; ++index) {
        SER = Byte & (0x80 >> index);
        SRK = 1;
        SRK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void Init74HC595() {
//  要产生上升沿先置为低电平
    RCK = 0;
    SRK = 0;
    while (1) {
        P0 = 0xE0;
        WriteByteTo74HC595(0x0f);
    }
}
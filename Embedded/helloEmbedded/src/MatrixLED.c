//
// Created by 徐洁 on 2023/11/7.
//

#include "MatrixLED.h"
#include "common.h"
#include "mcs51/8052.h"

#define Len(array) sizeof(array)/sizeof(array[0])

__sbit __at (0xB4) SER ; // SER
__sbit __at (0xB5) RCK ; // RCLK
__sbit __at (0xB6) SRK ; // SERCLK

void WriteByteTo74HC595(unsigned char Byte) {
    // 先把最高位取出，依次位移时
    // 1000 0000 0x80
    for (int index = 0; index < 8; ++index) {
        SER = Byte & (0x80 >> index);
        SRK = 1;
        SRK = 0;
    }
    RCK = 1;
    RCK = 0;
}

void ColumnLEDLight(unsigned char column, unsigned char Byte) {
    // 段选 位选 段选 位选
    WriteByteTo74HC595(Byte);
    P0 = ~(0x80 >> column);
    setTimeOut(1);
    P0 = 0xFF;
}

// 绘制斜线图像
void SlashGraph() {
    ColumnLEDLight(0, 0x80);
    ColumnLEDLight(1, 0x40);
    ColumnLEDLight(2, 0x20);
    ColumnLEDLight(3, 0x10);
    ColumnLEDLight(4, 0x08);
    ColumnLEDLight(5, 0x04);
    ColumnLEDLight(6, 0x02);
    ColumnLEDLight(7, 0x01);
}

// 绘制笑脸
void SmileGraph() {
    ColumnLEDLight(0, 0x80);
    unsigned char list[8] = {0x3C, 0x42, 0x91, 0x85, 0x85, 0x91, 0x42, 0x3C,};
    for (int i = 0; i < Len(list); ++i) {
        ColumnLEDLight(i, list[i]);
    }
}
void Init74HC595() {
//  要产生上升沿先置为低电平
    RCK = 0;
    SRK = 0;
    while (1) {
        SmileGraph();
    }
}
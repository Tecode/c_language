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
// 使用关键字__code变量会放置在flash中，不可以用被更改
void SmileGraph() {
    unsigned char list[] = {0x3C, 0x42, 0xA9, 0x85, 0x85, 0xA9, 0x42, 0x3C};
    for (int i = 0; i < Len(list); ++i) {
        ColumnLEDLight(i, list[i]);
    }
}

// 绘制文本动画
// 使用关键字__code变量会放置在flash中，不可以用被更改
void AnimationGraph() {
    unsigned char offset = 0;
    unsigned char count = 0;
    unsigned char __code animationList[] = {
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
            0xFF,0x08,0x08,0x08,0xFF,0x00,0x00,0xFF,
            0x89,0x89,0x89,0x89,0x00,0x00,0xFF,0x01,
            0x01,0x01,0x01,0x00,0xFF,0x01,0x01,0x01,
            0x01,0x00,0x00,0x3C,0x42,0x81,0x81,0x42,
            0x3C,0x00,0x00,0xFD,0x00,0x00,0xFF,0x10,
            0x10,0x10,0xFF,0x00,0x00,0x00,0x1F,0x64,
            0xC4,0xC4,0x64,0x1F,0x00,0x00,0x00,0x7E,
            0x81,0x81,0x7E,0x22,0x22,0xE3,0x00,0x00,
            0x00,0x80,0x81,0x81,0xFF,0x81,0x81,0x80,
            0x00,0x00,0x18,0x18,0x99,0x5A,0x3C,0xFF,
            0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };
    while (1) {
        for (int index = 0; index < 8; ++index) {
            ColumnLEDLight(index, animationList[index + offset]);
        }

        count = count + 1;

        if (offset == Len(animationList) - 8) {
            offset = 0;
        }

        if (count == 10) {
            offset = offset + 1;
            count = 0;
        }
    }
}

void Init74HC595() {
//  要产生上升沿先置为低电平
    RCK = 0;
    SRK = 0;
//    while (1) {
//        AnimationGraph();
//    }
    AnimationGraph();
}
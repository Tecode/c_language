//
// Created by 昊轩 on 2023/11/2.
//

#include "matrixButton.h"
#include "mcs51/8052.h"
#include "common.h"
#include "LCD1602.h"

unsigned char matrixKeyValue() {
    unsigned char keyValue = 0;
    // 按列扫描P13 P12 P11 P10
    // 全部重置为关闭状态
    // 第一列--------------------------------------------------------
    P1 = 0xFF;
    P1_3 = 0;
    if (P1_7 == 0) {
        setTimeOut(20);
        while (P1_7 == 0);
        setTimeOut(20);
        keyValue = 1;
    }
    if (P1_6 == 0) {
        setTimeOut(20);
        while (P1_6 == 0);
        setTimeOut(20);
        keyValue = 5;
    }
    if (P1_5 == 0) {
        setTimeOut(20);
        while (P1_5 == 0);
        setTimeOut(20);
        keyValue = 9;
    }
    if (P1_4 == 0) {
        setTimeOut(20);
        while (P1_4 == 0);
        setTimeOut(20);
        keyValue = 13;
    }
    // 第二列--------------------------------------------------------
    P1 = 0xFF;
    P1_2 = 0;
    if (P1_7 == 0) {
        setTimeOut(20);
        while (P1_7 == 0);
        setTimeOut(20);
        keyValue = 2;
    }
    if (P1_6 == 0) {
        setTimeOut(20);
        while (P1_6 == 0);
        setTimeOut(20);
        keyValue = 6;
    }
    if (P1_5 == 0) {
        setTimeOut(20);
        while (P1_5 == 0);
        setTimeOut(20);
        keyValue = 10;
    }
    if (P1_4 == 0) {
        setTimeOut(20);
        while (P1_4 == 0);
        setTimeOut(20);
        keyValue = 14;
    }
    // 第三列--------------------------------------------------------
    P1 = 0xFF;
    P1_1 = 0;
    if (P1_7 == 0) {
        setTimeOut(20);
        while (P1_7 == 0);
        setTimeOut(20);
        keyValue = 3;
    }
    if (P1_6 == 0) {
        setTimeOut(20);
        while (P1_6 == 0);
        setTimeOut(20);
        keyValue = 7;
    }
    if (P1_5 == 0) {
        setTimeOut(20);
        while (P1_5 == 0);
        setTimeOut(20);
        keyValue = 11;
    }
    if (P1_4 == 0) {
        setTimeOut(20);
        while (P1_4 == 0);
        setTimeOut(20);
        keyValue = 15;
    }
    // 第四列--------------------------------------------------------
    P1 = 0xFF;
    P1_0 = 0;
    if (P1_7 == 0) {
        setTimeOut(20);
        while (P1_7 == 0);
        setTimeOut(20);
        keyValue = 4;
    }
    if (P1_6 == 0) {
        setTimeOut(20);
        while (P1_6 == 0);
        setTimeOut(20);
        keyValue = 8;
    }
    if (P1_5 == 0) {
        setTimeOut(20);
        while (P1_5 == 0);
        setTimeOut(20);
        keyValue = 12;
    }
    if (P1_4 == 0) {
        setTimeOut(20);
        while (P1_4 == 0);
        setTimeOut(20);
        keyValue = 16;
    }
    return keyValue;
}


unsigned char keyNumber;
// 按下按钮显示数字
void matrixKeyDown() {
    LCD_Init();
    LCD_ShowString(1, 1, "MatrixNumber:");
    while (1) {
        if (keyNumber) {
            LCD_ShowNum(1, 2, keyNumber, 2);
        }
    }
}

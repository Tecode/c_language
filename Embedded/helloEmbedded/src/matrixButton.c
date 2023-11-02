//
// Created by 昊轩 on 2023/11/2.
//

#include "matrixButton.h"
#include "mcs51/8052.h"
#include "common.h"
#include "LCD1602.h"

#define Password 7758

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
unsigned char count = 0;
unsigned int password = 0;

// 按下按钮显示数字,实现4位数密码 S1-S9
// S10 确定 S11取消
void matrixKeyDown() {
    LCD_Init();
    LCD_ShowString(1, 1, "Password:");
    while (1) {
        keyNumber = matrixKeyValue();
        if (keyNumber && count < 4 && keyNumber < 10) {
            count++;
            password = password * 10 + keyNumber;
            LCD_ShowNum(2, 1, password, 4);
        }
        if (keyNumber == 10) {
            if (Password == password) {
                LCD_ShowString(1, 14, "OK");
            } else {
                LCD_ShowString(1, 14, "ERR");
            }
        }
        if (keyNumber == 11) {
            password = 0;
            count = 0;
            LCD_ShowNum(2, 1, password, 4);
            break;
        }
    }
}

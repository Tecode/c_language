//
// Created by 徐洁 on 2023/11/6.
//

#include "Uart.h"
#include "mcs51/8052.h"
#include "common.h"

unsigned char uartCount = 0x01;

void TransmitByte(unsigned char data) {
    SBUF = data;
    while (TI == 0);
    TI = 0;
}

void UartInit()        //4800bps@11.0592MHz
{
    PCON &= 0x7F;        //波特率不倍速
    SCON = 0x50;        //8位数据,可变波特率
    TMOD &= 0x0F;        //设置定时器模式
    TMOD |= 0x20;        //设置定时器模式
    TL1 = 0xFA;            //设置定时初始值
    TH1 = 0xFA;            //设置定时重载值
    ET1 = 0;            //禁止定时器中断
    TR1 = 1;            //定时器1开始计时

    ES = 1; // 允许串行口1中断
    EA = 2; // CPU开放中断

    while (1) {}
}
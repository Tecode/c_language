//
// Created by 昊轩 on 2023/11/3.
//

#include "timer.h"
#include "mcs51/8052.h"


void Timer0_Init(void)        //1毫秒@11.0592MHz
{
    TMOD &= 0xF0;            //设置定时器模式
    TMOD |= 0x01;            //设置定时器模式
    TL0 = 0x18;                //设置定时初始值
    TH0 = 0xFC;                //设置定时初始值
    TF0 = 0;                //清除TF0标志
    TR0 = 1;                //定时器0开始计时
//    配置中断（中断系统）
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}


void runTimer() {
    P2_3 = 0;
    Timer0_Init();
    while (1) {

    }
}

// 执行中断函数
unsigned char timer0Count = 0;

void Timer0_Routine()

__interrupt 1 {
//    timeCount ++;
//    if (timeCount == 1000) {
//        timeCount = 0;
//    }
P2_0 = 0;
}
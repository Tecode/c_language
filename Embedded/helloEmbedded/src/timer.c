//
// Created by 昊轩 on 2023/11/3.
//

#include "timer.h"
#include "mcs51/8052.h"
#include "LCD1602.h"


void Timer0_Init(void)        //1毫秒@11.0592MHz
{
    TMOD &= 0xF0;            //设置定时器模式
    TMOD |= 0x01;            //设置定时器模式
    TL0 = 0x66;                //设置定时初始值
    TH0 = 0xFC;                //设置定时初始值
    TF0 = 0;                //清除TF0标志
    TR0 = 1;                //定时器0开始计时
//    配置中断（中断系统）
    ET0 = 1;
    EA = 1;
    PT0 = 0;
    while (1) {}
}

/**
  * @brief  流水灯（基于寄存器地址P2）使用定时器，指定亮灯位置
  * @param  index 起始行位置，范围：1~8
  * @retval 无
  */
void litLight(unsigned char index) {
    // 0111 1111 127
    // 1011 1111 191
    // 1101 1111 223
    // 1110 1111 239
    // 1111 0111 247
    // 1111 1011 251
    // 1111 1101 253
    // 1111 1110 254
    // 1111 1111 255
    P2 = 0xFF - (1 << (index - 1));
}

/**
  * @brief  流水灯
  * @retval 无
  */
void cycleLightUp() {
    static unsigned char loopIndex = 1;
    static unsigned char add = 1;
    if (loopIndex == 8) {
        add = 0;
    }
    if (loopIndex == 1) {
        add = 1;
    }
    litLight(loopIndex);
    if (add) {
        loopIndex++;
    } else {
        loopIndex--;
    }
}

/**
  * @brief  闹钟计时器显示 时：分：秒
  * @retval 无
  */
void alarmTimer() {
    static unsigned char init = 0;
    if (!init) {
        LCD_Init();
    }
    init = 1;
    static unsigned int second = 0;
    LCD_ShowString(1, 1, "Alarm Timer:");
    LCD_ShowChar(2, 3, ':');
    LCD_ShowChar(2, 6, ':');
    //    时
    LCD_ShowNum(2, 1, second / 3600, 2);
    //    分
    LCD_ShowNum(2, 4, second / 60, 2);
    //    秒
    LCD_ShowNum(2, 7, second % 60, 2);
    second++;
}
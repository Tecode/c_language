#include "common.h"
#include "matrixButton.h"
#include "timer.h"
#include "mcs51/8052.h"
#include "LCD1602.h"
#include "Uart.h"


// 执行定时器中断函数，需要在main中才可以被執行
void Timer0_Routine() __interrupt 1 {
    static unsigned int Timer_0_Count = 0;
    Timer_0_Count++;
    TL0 = 0x66;                //设置定时初始值
    TH0 = 0xFC;                //设置定时初始值
    if (Timer_0_Count >= 1000) {
        Timer_0_Count = 0;
        //        P2_3 = P2_3 ^ 1;
        //显示流水灯
        //cycleLightUp();
        // 闹钟提示
        alarmTimer();
    }
}

// 执行串口1中断
void URAT1_Routine()  __interrupt 4 {
    while(RI == 0);
    RI = 0;
    P2 = SBUF;
    //    接收完数据再发回电脑端
    TransmitByte(SBUF);
}

int main() {
// write your code here
//    while (1) {
//      blinkLight();
//      waterLamps();
//        break;
//    }
//    buttonControlLight01();
//    buttonControlLight02();
//    buttonControlLight03();
//    loopLight();
//    numberLight();
//    matrixKeyDown();
//  定时器初始化
//    Timer0_Init();
//  初始化串口1
    UartInit();
    return 0;
}
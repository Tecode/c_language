#include "common.h"
#include "matrixButton.h"
#include "timer.h"
#include "mcs51/8052.h"

// 执行中断函数，需要在main中才可以被執行
void Timer0_Routine() __interrupt 1 {
static unsigned int Timer_0_Count = 0;
Timer_0_Count ++;
    TL0 = 0x18;                //设置定时初始值
    TH0 = 0xFC;                //设置定时初始值
    if (Timer_0_Count >= 1000) {
        Timer_0_Count = 0;
    //        P2_3 = P2_3 ^ 1;
    //显示流水灯
    cycleLightUp();
    }
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
    Timer0_Init();
    return 0;
}
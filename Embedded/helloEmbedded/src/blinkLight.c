//
// Created by 徐洁 on 2023/10/28.
//
#include "mcs51/8052.h"
#include "common.h"

// 闪烁的小灯
void blinkLight() {
    setTimeOut(1000);
    P2 = 0xFE;
    setTimeOut(1000);
    P2 = 0x00;
}

// 流水灯（基于寄存器地址P2）
void waterLamps01() {

}
#include "common.h"

void nop() {}

// 软件延时计算器
void setTimeOut(unsigned int ms)    //@11.0592MHz
{
    unsigned char i, j;
    while (ms) {
        nop();
        i = 2;
        j = 199;
        do {
            while (--j);
        } while (--i);
        ms --;
    }
}
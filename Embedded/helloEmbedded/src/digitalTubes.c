//
// Created by 昊轩 on 2023/10/31.
//

#include "mcs51/8052.h"
#include "common.h"

// 静态数码管显示，输入数字是多少显示多少 1-8
void staticDisplay(unsigned char number) {
    P2_4 = 1;
    P2_3 = 0;
    P2_2 = 1;
}
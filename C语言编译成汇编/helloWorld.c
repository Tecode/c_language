//
// Created by 昊轩 on 2021/12/17.
//
// 编译成汇编 gcc -S ./helloWorld.c
#include "stdio.h"

void hello() {
    printf("--->>");
}

int main() {
    int a = 4;
    int b = 6;
    int c;
    c = a + b;
    printf("%d", c);
    hello();
    return 0;
}
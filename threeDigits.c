//
// Created by 昊轩 on 2022/9/27.
//
#include "stdio.h"

int loop(int value) {
    printf("%d \n", value);
    return 0;
}

int main() {
    for (int index = 1; index < 5; ++index) {
        loop(index);
//        printf("%d", index);
    }
    return 0;
}
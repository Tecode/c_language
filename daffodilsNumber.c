//
// Created by Administrator on 2022/9/25.
//

#include "stdio.h"

int cube(const int value) {
    return value * value * value;
}

int main() {
    int number, value1, value2, value3, count = 0;
    printf("请输入一个3位数：\n");
    scanf("%d",&number);
    for (int i = 100; i <= number; ++i) {
        value1 = i / 100;
        value2 = i / 10 % 10;
        value3 = i % 10;
        int sum = cube(value1) + cube(value2) + cube(value3);
        if (sum == i) {
            printf("水仙花数：%d \n", i);
            count ++;
            continue;
        }
    }
    printf("水仙花数一共有 %d 个\n", count);
    return 0;
}



//888
//水仙花数：153
//水仙花数：370
//水仙花数：371
//水仙花数：407
//水仙花数一共有 4 个
//
// Created by Administrator on 2022/9/25.
//

#include "stdio.h"

int cube(const int value) {
    return value * value * value;
}

int main() {
    int number, value1, value2, value3, count = 0;
    printf("������һ��3λ����\n");
    scanf("%d",&number);
    for (int i = 100; i <= number; ++i) {
        value1 = i / 100;
        value2 = i / 10 % 10;
        value3 = i % 10;
        int sum = cube(value1) + cube(value2) + cube(value3);
        if (sum == i) {
            printf("ˮ�ɻ�����%d \n", i);
            count ++;
            continue;
        }
    }
    printf("ˮ�ɻ���һ���� %d ��\n", count);
    return 0;
}



//888
//ˮ�ɻ�����153
//ˮ�ɻ�����370
//ˮ�ɻ�����371
//ˮ�ɻ�����407
//ˮ�ɻ���һ���� 4 ��
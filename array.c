//
// Created by 昊轩 on 2023/10/30.
//

#include "stdio.h"
#include <unistd.h>
#include <stdlib.h>

#define Len(array) sizeof(array)/sizeof(array[0])

int main() {
    int num = 0xF0 + 0x01;
    printf("%x \n", num);
    //    静态数组
    int list[] = {2, 4, 5, 67,};
    for (int index = 0; index < Len(list); ++index) {
        sleep(1);
        printf("%d \n", index);
    }
    //    动态数组
    int *dynamicArr = (int *) malloc(sizeof(int) * 5);
    if (dynamicArr == NULL) {
        printf("%s", "内存已满");
        return 0;
    }
    dynamicArr[2] = 3;
    printf("%x", *dynamicArr);
    free(dynamicArr);
    return 0;
}
#include "common.h"


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
// 数字从1-8，1秒变一次
    for (unsigned char index = 1; index < 9; index ++) {
        setTimeOut(1000);
        staticDisplay(index);
    }
    return 0;
}

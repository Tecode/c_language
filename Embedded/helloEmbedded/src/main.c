//#include "common.h"
//#include "mcs51/8052.h"
#include "LCD1602.h"


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
    LCD_Init();
//    LCD_ShowChar(1, 1, 'A');
//    LCD_ShowString(1,1, "Hello world!");
    LCD_ShowSignedNum(1,2,234,4);
    return 0;

}

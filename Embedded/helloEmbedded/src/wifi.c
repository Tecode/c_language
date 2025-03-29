//
// Created by haoxuan on 2025/3/4.
//
// 包含必要的头文件
#include <reg52.h>  // 51单片机寄存器定义
#include <intrins.h>  // 延时函数
#include <string.h>   // 字符串操作

// 引脚定义
sbit LED = P1 ^ 0;  // 状态指示灯（可选）
sbit CHARGE_CONTROL = P1 ^ 1;  // 充电控制引脚（示例）

// 串口相关定义
#define BAUD_RATE 9600  // 波特率
#define FOSC 11059200L  // 晶振频率（11.0592MHz）

// 全局变量
unsigned char receive_buffer[50];  // 接收缓冲区
unsigned char buffer_index = 0;    // 缓冲区索引
bit data_received = 0;             // 数据接收标志

// 函数声明
void UartInit(void);               // 串口初始化
void SendString(unsigned char *s); // 发送字符串
void DelayMs(unsigned int ms);     // 延时函数
void ProcessReceivedData(void);    // 处理接收数据
unsigned int ReadADC(void);        // 读取ADC值（模拟电压/电流检测）

// 主函数
void main(void) {
    UartInit();  // 初始化串口
    LED = 0;     // 初始状态灯关闭

    while (1) {
        unsigned int voltage = ReadADC();  // 读取电压值（示例）
        unsigned int current = ReadADC();  // 读取电流值（示例）

        // 构造发送数据（示例：JSON格式）
        unsigned char send_data[50];
        sprintf(send_data, "{\n\"voltage\":%d,\n\"current\":%d\n}", voltage, current);

        // 发送数据到Wi-Fi模块
        SendString("AT+CIPSEND=0,50\r\n");  // 设置发送长度
        DelayMs(100);  // 等待响应
        SendString(send_data);  // 发送数据
        DelayMs(1000);  // 等待1秒，防止数据堆积

        // 处理接收到的指令
        if (data_received) {
            ProcessReceivedData();
            data_received = 0;  // 清空标志
        }
    }
}

// 串口初始化
void UartInit(void) {
    SCON = 0x50;  // 串口工作模式1，8位数据位，1位停止位
    TMOD |= 0x20;  // 定时器1，工作模式2（8位自动重装）
    TH1 = 256 - (FOSC / 12 / 32 / BAUD_RATE);  // 设置波特率
    TL1 = TH1;
    TR1 = 1;  // 启动定时器1
    ES = 1;   // 启用串口中断
    EA = 1;   // 启用总中断
}

// 串口中断服务函数
void UartInterrupt(void)

interrupt 4
{
if (RI)  // 接收中断
{
RI = 0;  // 清空接收标志
receive_buffer[buffer_index] =
SBUF;  // 读取接收数据
if (receive_buffer[buffer_index] == '\n' || buffer_index >= 49)
{
receive_buffer[buffer_index + 1] = '\0';  // 字符串结束
data_received = 1;  // 设置数据接收标志
buffer_index = 0;   // 重置索引
}
else
{
buffer_index++;  // 增加索引
}
}
if (TI)  // 发送中断
{
TI = 0;  // 清空发送标志
}
}

// 发送字符串函数
void SendString(unsigned char *s) {
    while (*s) {
        SBUF = *s++;  // 发送一个字符
        while (!TI);  // 等待发送完成
        TI = 0;       // 清空发送标志
    }
}

// 延时函数（毫秒）
void DelayMs(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 120; j++);
}

// 处理接收数据
void ProcessReceivedData(void) {
    if (strstr(receive_buffer, "START_CHARGE"))  // 接收到启动充电指令
    {
        CHARGE_CONTROL = 1;  // 启动充电
        LED = 1;  // 点亮指示灯
        SendString("OK: Charging started\r\n");  // 反馈
    } else if (strstr(receive_buffer, "STOP_CHARGE"))  // 接收到停止充电指令
    {
        CHARGE_CONTROL = 0;  // 停止充电
        LED = 0;  // 关闭指示灯
        SendString("OK: Charging stopped\r\n");  // 反馈
    }
}

// 读取ADC值（模拟示例，需根据实际硬件实现）
unsigned int ReadADC(void) {
    // 这里假设使用外部ADC芯片（如ADC0832）通过SPI或I2C通信
    // 实际实现需根据硬件电路修改
    return 1200;  // 示例返回值（电压或电流值）
}
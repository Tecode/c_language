using System;

namespace HelloWorldApplication
{
    // 派生类基类
    public class BaseApplication
    {
        protected BaseApplication(int value)
        {
            Console.WriteLine("Hello BaseApplication! 参数：{0}", value);
        }
    }
}
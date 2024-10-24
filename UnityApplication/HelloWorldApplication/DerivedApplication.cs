using System;

namespace HelloWorldApplication
{
    // 派生类
    public class DerivedApplication : BaseApplication
    {
        public DerivedApplication() : base(99)
        {
            Console.WriteLine("DerivedApplication");
        }
    }
}
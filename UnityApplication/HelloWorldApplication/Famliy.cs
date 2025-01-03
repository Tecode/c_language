#define IS_DEBUG

using System;
using System.Diagnostics;

namespace HelloWorldApplication
{
    internal struct FamilyStruct
    {
        public string Name;
        public short Age;
    }

    internal enum State
    {
        Star,
        Pause,
        Failed
    }

    public class Family : Haoxuan
    {
        [Obsolete("方法废弃了使用Say方法", true)]
        public override void SayName()
        {
            base.SayName();
            Console.WriteLine("继承的属性方法SayName");
        }

        public override void ReadBook()
        {
            Console.WriteLine("实现抽象方法");
        }

        public Family()
        {
            const int age = 2;
            Console.WriteLine("构造函数初始化 {0}", age);
        }

        public void Say()
        {
            var num = Convert.ToInt32("89");
            const string name = "hao/xuan //n cool!";
            FamilyStruct familyStruct;
            familyStruct.Name = "Miaomiao";
            familyStruct.Age = 1;
            Console.WriteLine("家庭成员:{0} {1} {2}", name, num + 1, State.Failed);
            Console.WriteLine("家庭成员:{0} 年龄：{1}岁", familyStruct.Name, familyStruct.Age);
        }


        // 定义了DEBUG2宏才会被调用
        // DebuggerStepThrough可以直接跳过这个方法的DEBUG调试
        [Conditional("IS_DEBUG"), DebuggerStepThrough]
        public static void ConditionalFunc()
        {
            Console.WriteLine("IS_DEBUG定义了宏才会被调用");
        }
    }
}
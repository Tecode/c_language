using System;

namespace HelloWorldApplication
{
    internal delegate void TotalCount(int val);

    public class AnonymousFunction
    {
        private readonly TotalCount _func = delegate(int value)
        {
            Console.WriteLine("匿名函数输入：{0}", value);
        };

        private static void OutPut(int value)
        {
            Console.WriteLine("事件委托输出结果：{0}", value);
        }
        // Lambda 表达式
        private readonly Func<int, int, int> _sum = (int value001, int value002) => value002 + value001;

        public static void Run()
        {
            var anonymous = new AnonymousFunction();
            TotalCount func = OutPut;
            Console.WriteLine("Lambda表达式总和：{0}", anonymous._sum(100, 2));
            func(100);
            anonymous._func(23);
        }
    }
}
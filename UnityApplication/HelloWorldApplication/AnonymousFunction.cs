using System;

namespace HelloWorldApplication
{
    internal delegate void TotalCount(int val);

    public class AnonymousFunction
    {
        // 匿名方法
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

        private static void Invoke(int value)
        {
            Console.WriteLine("Invoke {0}", value);
        }

        public static void Run()
        {
            Func<int, int> LambdaFunc = (val) =>
            {
                Console.WriteLine(val);
                return val;
            };
            var anonymous = new AnonymousFunction();
            TotalCount func = OutPut;
            Console.WriteLine("Lambda表达式总和：{0}", anonymous._sum(100, 2));
            func(100);
            var invoke = new TotalCount(Invoke);
            invoke(90);
            LambdaFunc(100);
            anonymous._func(23);
        }
    }
}
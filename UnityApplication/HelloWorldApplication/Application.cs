using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace HelloWorldApplication
{
    internal abstract class Application
    {
        // 数组参数
        private static int TotalCount(IEnumerable<int> array)
        {
            return array.Sum();
        }

        // 参数数组
        private static int ArrayParam(params int[] param)
        {
            return param.Sum();
        }

        public static void Main(string[] args)
        {
            var array = new[] { 2, 32, 45 };
            var sum = TotalCount(new[] { 1, 2, 4 });
            var total = ArrayParam(1, 2, 3, 4);
            AnonymousFunction.Run();
            Console.WriteLine("总和：{0} {1} {2}", sum, array.Length, total);
            const float hp = 100F;
            var family = new Family();
            var application = new SealedFunction();
            // 派生类
            var derivedApplication = new DerivedApplication();
            for (var index = 0; index < 10; index++)
            {
                if (index == 5)
                {
                    break;
                }

                Console.WriteLine("Hello World jie jie {0} {1}", index, hp);
            }

            // 列表
            var list = new List<int> { 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            list.ForEach(Console.WriteLine);
            // 泛型
            var generics = new GenericsApplication<string>("Lock", "Unlock");
            generics.GenericsFunction("90");
            Console.WriteLine("范型类输入结果：{0}", generics.Print());

            const string val = "hooks";
            var insert = val.Insert(0, "2");
            var result = string.Compare(insert, "2hooks", StringComparison.Ordinal);
            // result = 0 相等 负数表示字符串不相等
            Console.WriteLine("字符串比较的结果：{0}", result);
            // 初始化字符串
            var val2 = new StringBuilder("hao xuan");
            // 创建一个可以包含20个字符的字符串
            var val3 = new StringBuilder(20);
            val3.Append('a');

            Console.WriteLine("StringBuilder 创建的字符串：{0} {1}", val2, val3);

            // 正则表达式
            var reg = new Regex(@"\d+");
            var isMatch = reg.IsMatch("5");
            Console.WriteLine("正则表达式：{0}", isMatch);

            family.Say();
            family.SayName();
            family.ReadBook();
            application.RunLog();
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;

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
            Console.WriteLine("总和：{0} {1} {2}", sum, array.Length, total);
            const float hp = 100F;
            var family = new Family();
            for (var index = 0; index < 10; index++)
            {
                if (index == 5)
                {
                    break;
                }

                Console.WriteLine("Hello World haoxuan {0} {1}", index, hp);
            }

            family.Say();
            // Console.ReadKey();
        }
    }
}
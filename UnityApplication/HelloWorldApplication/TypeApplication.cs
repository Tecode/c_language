using System;

namespace HelloWorldApplication
{
    public class TypeApplication
    {
        public static void Run()
        {
            var cat = new Cat();
            var type = cat.GetType();
            Console.WriteLine(type.Name);
            Console.WriteLine(type.Namespace);
            // 获取到所有的public属性
            foreach (var fieldInfo in type.GetFields())
            {
                Console.WriteLine(fieldInfo.Name);
            }

            // 获取到所有的public方法
            foreach (var methodInfo in type.GetMethods())
            {
                Console.WriteLine(methodInfo.Name);
            }
            // 获取所在程序集
            Console.WriteLine(type.Assembly);
            foreach (var type1 in type.Assembly.GetTypes())
            {
                Console.WriteLine(type1.Name);
            }
        }
    }
}
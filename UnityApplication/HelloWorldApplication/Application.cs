using System;

namespace HelloWorldApplication
{
    internal class Application
    {
        public static void Main(string[] args)
        {
            for (int index = 0; index < 10; index++)
            {
                Console.WriteLine("Hello World haoxuan {0}", index);
            }
            Console.ReadKey();
        }
    }
}
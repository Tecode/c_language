using System;

namespace HelloWorldApplication
{
    internal abstract class Application
    {
        public static void Main(string[] args)
        {
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
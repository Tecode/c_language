using System;

namespace HelloWorldApplication
{
    // 密封类不能被继承
    // public sealed class SealedApplication
    public class SealedApplication
    {
        public virtual void RunLog()
        {
            Console.WriteLine("Hello World SealedApplication");
        }
    }
}
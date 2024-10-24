using System;

namespace HelloWorldApplication
{
    public class SealedFunction : SealedApplication
    {
        // 密封方法不能被继承
        public sealed override void RunLog()
        {
            base.RunLog();
            Console.WriteLine("SealedFunction RUNNING");
        }
    }
}
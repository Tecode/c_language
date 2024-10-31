using System;

namespace HelloWorldApplication
{
    public class Cat
    {
        public Action CatCommon;
        public void Running()
        {
            Console.WriteLine("快，好多老鼠，哪里跑！！");
            CatCommon?.Invoke();
        }
    }
}
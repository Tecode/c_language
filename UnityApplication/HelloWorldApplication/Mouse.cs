using System;

namespace HelloWorldApplication
{
    public class Mouse
    {
        private readonly string _name;

        public Mouse(string name, Cat cat)
        {
            _name = name;
            cat.CatCome += Moving;
        }

        public void Moving()
        {
            Console.WriteLine("猫来了，{0}快跑！！", _name);
        }
    }
}
using System;

namespace HelloWorldApplication
{
    public class Mouse
    {
        private readonly string _name;

        public Mouse(string name)
        {
            _name = name;
        }

        public void Movving()
        {
            Console.WriteLine("猫来了，{0}快跑！！", _name);
        }
    }
}
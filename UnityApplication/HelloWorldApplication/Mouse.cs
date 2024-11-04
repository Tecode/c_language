using System;

namespace HelloWorldApplication
{
    public class Mouse
    {
        private readonly string _name;
        public int CatId;
        public string Name;

        public Mouse(string name, Cat cat)
        {
            _name = name;
            cat.CatCome += Moving;
        }
        
        public Mouse(){}

        private void Moving()
        {
            Console.WriteLine("猫来了，{0}快跑！！", _name);
        }

        public override string ToString()
        {
            return $"CatId:{CatId}, Name:{Name}";
        }
    }
}
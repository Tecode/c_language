using System;

namespace HelloWorldApplication
{
    public class Cat
    {
        public int Id;
        public string Name;
        public float Age;
        // event 声明一个事件，只能内部自己调用外部不能触发
        public event Action CatCome;
        public void Running()
        {
            Console.WriteLine("快，好多老鼠，哪里跑！！");
            CatCome?.Invoke();
        }

        public override string ToString()
        {
            return $"ID: {Id}, Name: {Name}, Age: {Age}";
        }
    }
}
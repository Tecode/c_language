using System;

namespace HelloWorldApplication
{
    public class CatApplication
    {
        public static void Run()
        {
            var cat = new Cat();
            var mouse001 = new Mouse("风车车");
            cat.CatCommon += mouse001.Movving;
            var mouse002 = new Mouse("米奇");
            cat.CatCommon += mouse002.Movving;
            var mouse003 = new Mouse("假老练");
            cat.CatCommon += mouse003.Movving;
            cat.Running();
        }
    }
}
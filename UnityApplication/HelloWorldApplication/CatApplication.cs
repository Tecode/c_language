using System;

namespace HelloWorldApplication
{
    public class CatApplication
    {
        public static void Run()
        {
            var cat = new Cat();
            var mouse001 = new Mouse("风车车", cat);
            // cat.CatCommon += mouse001.Moving;
            var mouse002 = new Mouse("米奇", cat);
            // cat.CatCommon += mouse002.Moving;
            var mouse003 = new Mouse("假老练", cat);
            // cat.CatCommon += mouse003.Moving;
            cat.Running();
        }
    }
}
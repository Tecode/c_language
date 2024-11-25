using System;

namespace HelloWorldApplication
{
    public class LinearTableApplication
    {
        public static void Run()
        {
            // 使用数组实现线性表
            // var app = new LinearTable<string>();

            // 使用单链表实现线性表
            var app = new SingleLinkedList<string>();
            app.Add("one");
            app.Add("two");
            app.Insert(2, "three");
            for (var index = 0; index < app.Length(); index++)
            {
                Console.WriteLine(app[index]);
            }

            Console.WriteLine("List Length:{0} IsEmpty:{1} LocalIndexOf three:{2}", app.Length(), app.IsEmpty(), app.LocalIndexOf("three"));
            app.Clear();
            Console.WriteLine("Clean -> List Length:{0} IsEmpty:{1}", app.Length(), app.IsEmpty());
        }
    }
}
using System;

namespace HelloWorldApplication
{
    public class LinearTableApplication
    {
        public static void Run()
        {
            var app = new LinearTable<string>();
            app.Add("one");
            app.Add("two");
            app.Insert(4, "three");
            foreach (var value in app.List)
            {
                Console.WriteLine(value);
            }

            Console.WriteLine("{0} {1} {2}", app.Length(), app.IsEmpty(), app.LocalIndexOf("three"));
            app.Clear();
            Console.WriteLine("{0} {1}", app.Length(), app.IsEmpty());
        }
    }
}
using System;
using System.Threading;

namespace HelloWorldApplication
{
    public class MultiThreadedApplication
    {
        private static void InvokeMethod(string val)
        {
            Thread.Sleep(1000);
            Console.WriteLine($"{val}");
        }

        private static void Download(object path)
        {
            Console.WriteLine($"开始下载, 路径{path}!");
            Thread.Sleep(1000);
            Console.WriteLine("下载完成!");
        }

        public static void Run()
        {
            // 通过Threaded类启动县城
            Action<string> action = InvokeMethod;
            // 开启一个新的线程
            var result = action.BeginInvoke("OK", (val) => Console.WriteLine(val.IsCompleted), null);
            if (result.AsyncWaitHandle.WaitOne(20000, false))
            {
                Console.WriteLine("Hello MultiThreadedApplication!");
                // return;
            }

            // 另一种创建线程传递参数的方法可以创建一个类，实例化传入参数然后调用类方法

            // 创建一个线程
            var tApplication = new Thread(Download);
            tApplication.Start("/cx");
            Console.ReadKey();
        }
    }
}
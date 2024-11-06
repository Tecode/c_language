using System;
using System.Threading;
using System.Threading.Tasks;

namespace HelloWorldApplication
{
    public class MultiTaskApplication
    {
        private static void RequestData(object data)
        {
            Console.WriteLine($"开始请求数据{data}");
            Thread.Sleep(2000);
            Console.WriteLine("请求数据完成");
        }

        public static void Run()
        {
            // Task任务执行多线程任务
            // var task = new Task(RequestData);
            // task.Start();

            // 线程池创建任务，执行后台短时间执行的任务，开启一个工作线程
            ThreadPool.QueueUserWorkItem(data => RequestData("传递的数据001"));
            ThreadPool.QueueUserWorkItem(RequestData, "传递的数据002");

            var raceFunc = new RaceThreaded();
            // 线程争用问题，如果是一个线程执行不会出现问题
            // ThreadPool.QueueUserWorkItem(raceFunc.Run, raceFunc);
            // ThreadPool.QueueUserWorkItem(raceFunc.Run, raceFunc);
            ThreadPool.QueueUserWorkItem(raceFunc.RunRace, raceFunc);
            ThreadPool.QueueUserWorkItem(raceFunc.RunRace, raceFunc);
            // 解决竞态问题加锁
            Console.ReadKey();
        }
    }
}
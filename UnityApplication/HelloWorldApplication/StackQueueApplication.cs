using System;
using System.Collections.Generic;

namespace HelloWorldApplication
{
    public class StackQueueApplication
    {
        public static void Run()
        {
            var inputValue = Console.ReadLine();
            var stack = new Stack<char>();
            var queue = new Queue<char>();

            if (inputValue != null)
            {
                foreach (var value in inputValue)
                {
                    stack.Push(value);
                    queue.Enqueue(value);
                }
            }
            
            // 判断是否是回文
            var isHuiWen = false;
            while (queue.Count > 0)
            {
                if (queue.Dequeue() != stack.Peek())
                {
                    isHuiWen = false;
                    break;
                }
                isHuiWen = true;
            }

            Console.WriteLine("isHuiWen: {0}", isHuiWen);
        }
    }
}
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace HelloWorldApplication
{
    public class SocketClientApplication
    {
        public static void Run()
        {
            // 创建新的客户端
            var client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            var point = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9091);
            // 连接到服务器
            client.Connect(point);
            var buffer = new byte[1024];
            // 接收数据
            var length = client.Receive(buffer);
            var message = Encoding.UTF8.GetString(buffer, 0, length);
            Console.WriteLine(message);
            var inputText = Console.ReadLine();
            if (inputText != null)
            {
                var sendBytes = Encoding.UTF8.GetBytes(inputText);
                client.Send(sendBytes);
            }

            Console.ReadKey();
        }
    }
}
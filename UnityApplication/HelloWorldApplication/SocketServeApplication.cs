using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace HelloWorldApplication
{
    public class SocketServeApplication
    {
        public static void Run()
        {
            var serve = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            serve.Bind(new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9091));
            var data = new byte[1024];
            serve.Accept();
            serve.Listen(100);
            while (true)
            {
                
            }
            Console.WriteLine("服务端开启接收");
            var receiveLength = serve.Receive(data);
            var text = Encoding.UTF8.GetString(data, 0, receiveLength);
            Console.WriteLine(text);
            Console.ReadKey();
        }
    }
}
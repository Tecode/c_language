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
            // 绑定IP和端口
            serve.Bind(new IPEndPoint(IPAddress.Parse("127.0.0.1"), 9091));
            // 最大链接数
            serve.Listen(100);
            // 开启服务端接收
            var serveAccept = serve.Accept();
            var text = "Hello, Welcome Connect To Server!";
            // 发送数据
            serveAccept.Send(Encoding.UTF8.GetBytes(text));
            // 接收数据
            var receiveData = new byte[1024];
            var length = serveAccept.Receive(receiveData);
            Console.WriteLine(Encoding.UTF8.GetString(receiveData, 0, length));
            Console.ReadKey();
        }
    }
}
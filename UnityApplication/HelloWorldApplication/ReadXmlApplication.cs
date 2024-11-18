using System;
using System.IO;
using System.Xml;

namespace HelloWorldApplication
{
    public class ReadXmlApplication
    {
        public static void Run()
        {
            var xml = new XmlDocument();
            xml.Load("/Users/haoxuan/Work/c_language/UnityApplication/HelloWorldApplication/Mac.xml");
            Console.WriteLine(xml.FirstChild);
            var firstNode = xml.ChildNodes[1];
            foreach (XmlNode xmlChildNode in firstNode.ChildNodes)
            {
                if (xmlChildNode.Name != "ItemGroup") continue;
                var runXml = new ReadXmlApplication();
                runXml.OutPut(xmlChildNode.ChildNodes);
                Console.WriteLine(xmlChildNode.ChildNodes.Count);
            }
        }

        private void OutPut(XmlNodeList nodeList)
        {
            foreach (XmlNode node in nodeList)
            {
                if (node.Attributes?["Include"] != null)
                {
                    Console.WriteLine(node.Attributes["Include"].Value);
                }
            }
        }
    }
}
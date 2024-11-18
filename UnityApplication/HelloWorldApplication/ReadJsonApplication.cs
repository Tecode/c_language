using System;
using System.IO;
using System.Text.Json.Nodes;

namespace HelloWorldApplication;

public class ReadJsonApplication
{
    public static void Run()
    {
        const string path = @"D:\project\c_language\UnityApplication\HelloWorldApplication\resource\data.json";
        var data = JsonNode.Parse(File.ReadAllText(path));
        foreach (var item in data?["orders"]?.AsArray()!)
        {
            Console.WriteLine(item?["orderId"]);
        }
    }
}
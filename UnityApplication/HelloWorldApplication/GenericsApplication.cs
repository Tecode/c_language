using System;

namespace HelloWorldApplication
{
    public class GenericsApplication<T>
    {
        private T _value1;
        private T _value2;

        public GenericsApplication(T val1, T val2)
        {
            _value1 = val1;
            _value2 = val2;
        }

        public string Print()
        {
            return _value1.ToString() + _value2.ToString();
        }

        public void GenericsFunction<T2>(T2 value)
        {
            switch (typeof(T2).Name)
            {
                case "String":
                    Console.WriteLine("范型参数类型是字符串，参数是{0}", value);
                    break;
                case "Int32":
                    Console.WriteLine("范型参数类型是{0},参数是{1}", typeof(T2).Name, value);
                    break;
            }
        }
    }
}
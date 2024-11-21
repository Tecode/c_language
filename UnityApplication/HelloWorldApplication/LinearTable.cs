using System;
using System.Linq;

namespace HelloWorldApplication
{
    public class LinearTable<T> : ILinearTable<T>
    {
        // 存放的数据
        private T[] _elements;

        // 元素个数
        private int _count;

        public LinearTable(int size)
        {
            _elements = new T[size];
        }

        public LinearTable() : this(10)
        {
        }

        public int Length()
        {
            return _count;
        }

        public bool IsEmpty()
        {
            return _count == 0;
        }

        public void Clear()
        {
            _count = 0;
            _elements = new T[10];
        }

        public T this[int index]
        {
            get => _elements[index];
            set => _elements[index] = value;
        }

        public T GetElement(int index)
        {
            return _elements[index];
        }

        public int LocalIndexOf(T value)
        {
            for (var index = 0; index < _elements.Length; index++)
            {
                if (_elements[index] != null && _elements[index].Equals(value))
                {
                    return index;
                }
            }

            return -1;
        }

        public void Insert(int index, T element)
        {
            if (_elements.Length == _count)
            {
                Console.WriteLine("Array is full");
                return;
            }

            if (index < 0 || index > _elements.Length)
            {
                Console.WriteLine("Index is out of range");
                return;
            }

            // 执行插入操作,将数据往后移动
            for (var value = _count - 1; value >= index; value--)
            {
                _elements[value + 1] = _elements[value];
            }

            _elements[index] = element;

            _count++;
        }

        public T RemoveAt(int index)
        {
            var data = default(T);
            if (index < 0 || index > _elements.Length || _count <= index)
            {
                Console.WriteLine("Index is out of range");
                return data;
            }
            data = _elements[index];
            for (var value = index + 1; value < _count; value++)
            {
                _elements[value - 1] = _elements[value];
            }
            _count--;
            return data;
        }

        public void Add(T element)
        {
            if (_elements.Length == _count)
            {
                Console.WriteLine("Array is full");
                return;
            }

            _elements[_count] = element;
            _count++;
        }
    }
}
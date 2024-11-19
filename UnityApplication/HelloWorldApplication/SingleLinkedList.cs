namespace HelloWorldApplication
{
    public class SingleLinkedList<T> : ILinearTable<T>
    {
        private LinkNode<T> _head = null;

        public int Length()
        {
            throw new System.NotImplementedException();
        }

        public bool IsEmpty()
        {
            throw new System.NotImplementedException();
        }

        public void Clear()
        {
            throw new System.NotImplementedException();
        }

        public T this[int index]
        {
            get => throw new System.NotImplementedException();
            set => throw new System.NotImplementedException();
        }

        public T GetElement(int index)
        {
            throw new System.NotImplementedException();
        }

        public int LocalIndexOf(T element)
        {
            throw new System.NotImplementedException();
        }

        public void Insert(int index, T element)
        {
            throw new System.NotImplementedException();
        }

        public void RemoveAt(int index)
        {
            throw new System.NotImplementedException();
        }

        public void Add(T element)
        {
            // 创建新的节点
            var node = new LinkNode<T>(element);
            if (_head == null)
            {
                _head = node;
                return;
            }
            var temp = _head;
            while (temp.Next != null)
            {
                temp = temp.Next;
            }
            temp.Next = node;
        }
    }
}
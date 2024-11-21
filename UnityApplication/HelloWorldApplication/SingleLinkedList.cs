namespace HelloWorldApplication
{
    public class SingleLinkedList<T> : ILinearTable<T>
    {
        private LinkNode<T> _head;

        public int Length()
        {
            if (_head == null) return 0;

            var temp = _head;
            var count = 1;
            while (temp.Next != null)
            {
                count++;
                temp = temp.Next;
            }

            return count;
        }

        public bool IsEmpty()
        {
            return _head == null;
        }

        public void Clear()
        {
            _head = null;
        }

        public T this[int index]
        {
            get
            {
                var temp = _head;
                // temp向后移动一个位置
                for (var i = 1; i <= index; i++)
                {
                    temp = temp.Next;
                }

                return temp.Data;
            }
            set => throw new System.NotImplementedException();
        }

        public T GetElement(int index)
        {
            var temp = _head;
            // temp向后移动一个位置
            for (var i = 1; i <= index; i++)
            {
                temp = temp.Next;
            }

            return temp.Data;
        }

        public int LocalIndexOf(T element)
        {
            if (_head == null) return -1;

            var temp = _head;
            var index = 0;
            while (temp.Next != null)
            {
                if (temp.Data.Equals(element))
                {
                    break;
                }

                index++;
                temp = temp.Next;
            }

            return index;
        }

        public void Insert(int index, T element)
        {
            // 创建新的节点
            var newNode = new LinkNode<T>(element);
            if (index == 0)
            {
                newNode.Next = _head;
                _head = newNode;
                return;
            }

            var temp = _head;
            // temp向后移动一个位置
            for (var i = 1; i <= index - 1; i++)
            {
                temp = temp.Next;
            }

            var preventNode = temp;
            var currentNode = temp.Next;
            preventNode.Next = newNode;
            newNode.Next = currentNode;
        }

        public T RemoveAt(int index)
        {
            T data = default;
            if (index == 0)
            {
                _head = _head.Next;
                return data;
            }

            var temp = _head;
            // temp向后移动一个位置
            for (var i = 1; i <= index - 1; i++)
            {
                temp = temp.Next;
            }

            var preventNode = temp;
            data = temp.Next.Data;
            var nextNode = temp.Next.Next;
            preventNode.Next = nextNode;
            return data;
        }

        public void Add(T element)
        {
            // 创建新的节点
            var newNode = new LinkNode<T>(element);
            if (_head == null)
            {
                _head = newNode;
                return;
            }

            var temp = _head;
            while (temp.Next != null)
            {
                temp = temp.Next;
            }

            temp.Next = newNode;
        }
    }
}
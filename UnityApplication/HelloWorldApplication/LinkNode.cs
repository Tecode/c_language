namespace HelloWorldApplication
{
    public class LinkNode<T>
    {
        private T _data;
        private LinkNode<T> _next;

        public LinkNode(T data, LinkNode<T> next)
        {
            _data = data;
            _next = next;
        }

        public LinkNode(T data)
        {
            _data = data;
        }

        public LinkNode()
        {
            _data = default;
        }

        public T Data
        {
            get => _data;
            set => _data = value;
        }

        public LinkNode<T> Next
        {
            get => _next;
            set => _next = value;
        }
    }
}
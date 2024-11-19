namespace HelloWorldApplication
{
    public interface ILinearTable<T>
    {
        int Length();
        bool IsEmpty();
        void Clear();
        T this[int index] { get; set; }
        T GetElement(int index);
        int LocalIndexOf(T element);
        void Insert(int index, T element);
        void RemoveAt(int index);
        void Add(T element);
    }
}
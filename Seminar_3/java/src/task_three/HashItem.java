package task_three;

public class HashItem<T>
{
        T value;
        T key;

        public HashItem(T value, T key)
        {
                this.key = key;
                this.value = value;
        }
}

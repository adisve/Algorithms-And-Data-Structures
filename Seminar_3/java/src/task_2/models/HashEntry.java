package task_2.models;

public class HashEntry<K, V> {
        public K key;
        public V value;

        public HashEntry(K key, V value)
        {
                this.key = key;
                this.value = value;
        }

        @Override
        public String toString()
        {
                return this.value.toString();
        }
}

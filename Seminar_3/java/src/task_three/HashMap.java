package task_three;

public interface HashMap<K, V> {
        public void set(K key, V value);
        public V get(K key);
        public Boolean has(K key);
        public void remove(K key);
}

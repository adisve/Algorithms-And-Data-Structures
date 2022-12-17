package task_2.interfaces;

public interface IHashTable<K, V> {

        void set(K key, V value);
        V get(K key);
        void remove(K key);
        boolean containsKey(K key);
        void rehash(int capacity);
        int hashcode(K key);
        void ensureLoadFactor();
        int size();
        public boolean isEmpty();
}

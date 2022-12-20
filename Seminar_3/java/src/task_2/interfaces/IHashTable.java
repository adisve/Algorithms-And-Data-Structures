package task_2.interfaces;

public interface IHashTable<K, V> {

        V set(K key, V value);
        V get(K key);
        boolean remove(K key);
        boolean containsKey(K key);
        void rehash(int capacity);
        int hashcode(K key);
        void ensureLoadFactor();
        int size();
        boolean isEmpty();
        void display();
}

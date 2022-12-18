package task_2.models;

public class HashNode<K, V> {
        public K key;
        public V value;
        public int hash;
        public HashNode<K, V> next;

        public HashNode(K key, V value, int hash, HashNode<K, V> next)
        {
                this.key = key;
                this.value = value;
                this.hash = hash;
                this.next = next;
        }
}

package task_2.models;

public class Node<K, V> {
        public K key;
        public V value;
        public int hash;
        public Node<K, V> next;

        public Node(K key, V value, int hash, Node<K, V> next)
        {
                this.key = key;
                this.value = value;
                this.hash = hash;
                this.next = next;
        }
}

package task_2.impl.separate_chaining;

import java.util.ArrayList;

import task_2.interfaces.IHashTable;
import task_2.models.HashNode;

/**
 * Separate chaining hash table
 */
public class HashTable<K, V> implements IHashTable<K, V> {

        private final int DEFAULT_CAPACITY = 8;
        private final float DEFAULT_LOAD_FACTOR = 0.5f;
        private ArrayList<HashNode<K, V>> entries = new ArrayList<HashNode<K, V>>(DEFAULT_CAPACITY);
        private int size = 0;
        private int capacity = DEFAULT_CAPACITY;

        public HashTable()
        {
                this.clear();
        }

        @Override
        public V set(K key, V value)
        {
                /* Generate index from hash */
                int headIndex = hashcode(key) % this.capacity;
                if (headIndex < 0)
                        headIndex *= -1;
                /* Unique hash */
                int hash = hashcode(key);
                HashNode<K, V> n = this.entries.get(headIndex);
                while (n != null)
                {
                        /** if the key is the same and also the hashcode,
                         * we update the existing value to avoid duplicates
                         */
                        if (n.key.equals(key) && n.hash == hash)
                        {
                                n.value = value;
                                return value;
                        }
                        n = n.next;
                }
                this.size += 1;
                /* Get original index from key again */
                n = this.entries.get(headIndex);
                HashNode<K, V> insertionNode = new HashNode<K, V>(key, value, hash, n);
                this.entries.set(headIndex, insertionNode);

                /* Ensure load factor is not exceeded (0.5f) */
                this.ensureLoadFactor();
                return value;
        }

        @Override
        public V get(K key)
        {
                /* Generate index from hash */
                int headIndex = hashcode(key) % this.capacity;
                if (headIndex < 0)
                        headIndex *= -1;
                /* Unique hash */
                int hash = hashcode(key);
                HashNode<K, V> n = this.entries.get(headIndex);
                while (n != null)
                {
                        if (n.key.equals(key) && n.hash == hash)
                                return n.value;
                        n = n.next;
                }
                return null;
        }

        @Override
        public boolean remove(K key)
        {
                /* Generate index from hash */
                int headIndex = this.hashcode(key) % this.capacity;
                if (headIndex < 0)
                        headIndex *= -1;
                /* Unique hash */
                int hash = this.hashcode(key);
                HashNode<K, V> n = this.entries.get(headIndex);
                HashNode<K, V> previousN = null;
                while (n != null)
                {
                        if (n.key.equals(key) && n.hash == hash)
                                break;
                        previousN = n;
                        n = n.next;
                }
                if (n == null)
                        return false;
                this.size -= 1;
                if (previousN != null)
                        previousN.next = n.next;
                else
                        this.entries.set(headIndex, n.next);
                if (this.size > 0 && this.size <= this.capacity/8)
                        this.rehash(this.capacity/2);
                return true;
        }

        @Override
        public void rehash(int capacity)
        {
                /* Rehash if exceed load factor */
                ArrayList<HashNode<K, V>> oldEntries = this.entries;
                this.capacity = capacity;
                this.entries = new ArrayList<HashNode<K, V>>(this.capacity);
                this.clear();
                for (HashNode<K, V> node : oldEntries) {
                        while(node != null)
                        {
                                this.set(node.key, node.value);
                                node = node.next;
                        }
                }
                
        }

        @Override
        public int hashcode(K key) {
                return 7 - (key.hashCode() % 7);
        }

        @Override
        public void ensureLoadFactor()
        {
                if ((1.0 * this.size) / this.capacity >= DEFAULT_LOAD_FACTOR)
                        this.rehash(this.capacity * 2);   
        }
        
        private void clear()
        {
                /* Clear entries */
                for (int i = 0; i < this.capacity; i++)
                        this.entries.add(null);
        }

        @Override
        public boolean containsKey(K key) {
                return this.get(key) != null;
        }

        @Override
        public int size() {
                return this.size;
        }

        @Override
        public boolean isEmpty() {
                return this.size == 0;
        }
}


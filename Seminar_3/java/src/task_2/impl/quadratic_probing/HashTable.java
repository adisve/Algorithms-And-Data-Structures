package task_2.impl.quadratic_probing;

import java.util.ArrayList;
import java.util.List;

import task_2.interfaces.IHashTable;
import task_2.models.HashEntry;

public class HashTable<K, V> implements IHashTable<K, V>{
        private final int DEFAULT_CAPACITY = 8;
        private final float DEFAULT_LOAD_FACTOR = 0.5f;

        private int size;
        private int capacity;
        private List<HashEntry<K, V>> entries;

    
        public HashTable(int capacity)
        {
                this.capacity = capacity;
                this.entries = new ArrayList<HashEntry<K, V>>(DEFAULT_CAPACITY);
                this.clear();
        }
        
        @Override
        public int size()
        {
                return size;
        }
    
        @Override
        public boolean isEmpty()
        {
                return size() == 0;
        }
    
        @Override
        public boolean containsKey(K key)
        {
                return get(key) != null;
        }
    
        @Override
        public int hashcode(K key)
        {
                return (7 - key.hashCode() % 7) % this.capacity;
        }
        
        @Override
        public void rehash(int capacity)
        {
                System.out.println("Rehashing table");
                HashTable<K, V> temp = new HashTable<K, V>(capacity);
                for (int i = 0; i < this.capacity; i++) {
                        if (this.entries.get(i) != null) {
                        temp.set(this.entries.get(i).key, this.entries.get(i).value);
                        }
                }
                this.entries = temp.entries;
                this.capacity = temp.capacity;
                System.out.println("Rehashed table");
        }
    
        @Override
        public void set(K key, V val)
        {
                if (val == null) remove(key);
                System.out.println("Current table capacity: " + this.capacity);
                this.ensureLoadFactor();
        
                int i;

                System.out.println("Inserting key " + key);
                for (i = hashcode(key); this.entries.get(i) != null; i = (i * i) % this.capacity) {
                        if (this.entries.get(i).key.equals(key))
                        { 
                                this.entries.set(i, new HashEntry<K, V>(this.entries.get(i).key, this.entries.get(i).value)); 
                                return; 
                        }
                }
                this.entries.set(i, new HashEntry<K, V>(key, val));
                this.size++;
        }
    
        @Override
        public V get(K key)
        {
                for (int i = hashcode(key); this.entries.get(i) != null; i = (i * i) % capacity) 
                        if (this.entries.get(i).key.equals(key))
                        return this.entries.get(i).value;
                return null;
        }
    
        @Override
        public void remove(K key)
        {
                if (!containsKey(key)) return;
        
                int i = hashcode(key);
                while (!key.equals(this.entries.get(i).key)) {
                        i = (i * i) % capacity;
                }
        
                this.entries.set(i, null);
        
                // Rehash
                i = (i * i) % capacity;
                while (this.entries.get(i) != null) {
                        K keyToRehash = this.entries.get(i).key;
                        V valToRehash = this.entries.get(i).value;
                        this.entries.set(i, null);
                        this.size--;  
                        set(keyToRehash, valToRehash);
                        i = (i * i) % capacity;
                }
                this.size--;        
        }

        @Override
        public void ensureLoadFactor()
        {
                if ((1.0 * this.size) / this.capacity >= DEFAULT_LOAD_FACTOR)
                {
                        System.out.println(this.size);
                        this.rehash(2 * this.capacity);
                } 
        }

        private void clear()
        {
                /* Clear entries */
                for (int i = 0; i < this.capacity; i++)
                        this.entries.add(null);
        }
}
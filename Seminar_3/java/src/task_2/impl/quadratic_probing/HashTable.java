package task_2.impl.quadratic_probing;

import java.util.ArrayList;
import java.util.List;

import task_2.interfaces.IHashTable;
import task_2.models.HashEntry;

/**
 * Hash table using quadratic probing
 */
public class HashTable<K, V> implements IHashTable<K, V>
{

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
            	return this.size;
        }
    
        @Override
        public boolean isEmpty()
        {
            	return this.size == 0;
        }
    
        @Override
        public boolean containsKey(K key)
        {
            	return get(key) != null;
        }
    
        @Override
        public int hashcode(K key)
        {
                return Math.abs((7 - (key.hashCode() % 7)) % this.capacity);
        }
    
        @Override
        public V set(K key, V val)
        {
		if (val == null) remove(key);

		this.ensureLoadFactor();
	
		/* Loop until a null entry is found, probing from hashcode(key) + i */
		int j = 0, hash;
		for (hash = hashcode(key); this.entries.get(hash) != null; hash = Math.abs((hash + (j * j)) % this.capacity), j++)
		{
			/** If the key is already in the table,
			 * update the old value to new one
			 */
			if (this.entries.get(hash).key.equals(key))
			{ 
				this.entries.set(hash, new HashEntry<K, V>(this.entries.get(hash).key, this.entries.get(hash).value)); 
				return val; 
			}
		}
		this.entries.set(hash, new HashEntry<K, V>(key, val));
		this.size++;
                return val;
        }
        
        @Override
        public V get(K key)
        {
                int j = 0;
		for (int hash = hashcode(key); this.entries.get(hash) != null; hash = Math.abs((hash + (j * j)) % this.capacity), j++) 
			if (this.entries.get(hash).key.equals(key))
			        return this.entries.get(hash).value;
		return null;
        }
    
        @Override
        public boolean remove(K key)
        {
		/* Go back if key is not present */
		if (!containsKey(key)) return false;
		
		/* Loop table until correct hash entry is found */
		int hash = hashcode(key), j = 0;
		while (!key.equals(this.entries.get(hash).key))
		{
                        hash = Math.abs((hash + (j * j)) % this.capacity);
                        j++;
                }
		
		/* Set hash entry to null */
		this.entries.set(hash, null);
	
		/* Rehash */
		hash = Math.abs((hash + (j * j)) % this.capacity);
		while (this.entries.get(hash) != null)
		{
			HashEntry<K, V> tHashEntry = this.entries.get(hash);
			this.entries.set(hash, null);
			this.size--;  
			set(tHashEntry.key, tHashEntry.value);
                        j++;
			hash = Math.abs((hash + (j * j)) % this.capacity);
		}
		this.size--;
                return true;     
        }

        /**
         * Rehash the table, storing the old HashEntries in a temp
         * table by iterating over the current table, swapping the entry tables
         * and changing the capacity
         */
        @Override
        public void rehash(int capacity)
        {
                int oldCapacity = this.capacity;
                this.capacity = capacity;
		HashTable<K, V> temp = new HashTable<K, V>(capacity);
		for (int i = 0; i < oldCapacity; i++) {
			if (this.entries.get(i) != null)
				temp.set(this.entries.get(i).key, this.entries.get(i).value);
		}
		this.entries = temp.entries;
        }

        @Override
        public void ensureLoadFactor()
        {
                if ((1.0 * this.size) / this.capacity >= DEFAULT_LOAD_FACTOR)
                        rehash(2*this.capacity);
        }

        private void clear()
        {
                /* Clear entries */
                for (int i = 0; i < this.capacity; i++)
                        this.entries.add(null);
        }

        @Override
        public void display() {
                for (int i = 0; i < this.capacity; i++)
                        System.out.print(" " + this.entries.get(i));
        }
}
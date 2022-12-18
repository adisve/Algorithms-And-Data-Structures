package task_2.impl.linear_probing;

import java.util.ArrayList;
import java.util.List;

import task_2.interfaces.IHashTable;
import task_2.models.HashEntry;

/**
 * Hash table using linear probing
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
		return (7 - key.hashCode() % 7) % this.capacity;
	}

	@Override
	public V set(K key, V val)
	{
		if (val == null) remove(key);
		

		this.ensureLoadFactor();

		/* Loop until a null entry is found, probing from hashcode(key) + i */
		int i;
		for (i = hashcode(key); this.entries.get(i) != null; i = (i + 1) % this.capacity)
		{
			/** If the key is already in the table,
			 * update the old value to new one
			 */
			if (this.entries.get(i).key.equals(key))
			{ 
				this.entries.set(i, new HashEntry<K, V>(this.entries.get(i).key, this.entries.get(i).value)); 
				return val; 
			}
		}
		this.entries.set(i, new HashEntry<K, V>(key, val));
		this.size++;
		return val;
	}
	
	@Override
	public V get(K key)
	{
		for (int i = hashcode(key); this.entries.get(i) != null; i = (i + 1) % capacity) 
			if (this.entries.get(i).key.equals(key))
				return this.entries.get(i).value;
		return null;
	}

	@Override
	public boolean remove(K key)
	{
		/* Go back if key is not present */
		if (!containsKey(key)) return false;
		
		/* Loop table until correct hash entry is found */
		int i = hashcode(key);
		while (!key.equals(this.entries.get(i).key))
			i = (i + 1) % capacity;
		
		/* Set hash entry to null */
		this.entries.set(i, null);

		/* Rehash */
		i = (i + 1) % capacity;
		while (this.entries.get(i) != null)
		{
			HashEntry<K, V> tHashEntry = this.entries.get(i);
			this.entries.set(i, null);
			this.size--;  
			set(tHashEntry.key, tHashEntry.value);
			i = (i + 1) % capacity;
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
		HashTable<K, V> temp = new HashTable<K, V>(capacity);
		for (int i = 0; i < this.capacity; i++) {
			if (this.entries.get(i) != null)
				temp.set(this.entries.get(i).key, this.entries.get(i).value);
		}
		this.entries = temp.entries;
		this.capacity = temp.capacity;
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
}
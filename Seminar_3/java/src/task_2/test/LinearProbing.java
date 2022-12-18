package task_2.test;

import java.util.concurrent.ThreadLocalRandom;
import task_2.impl.linear_probing.HashTable;
import task_2.interfaces.ITest;

public class LinearProbing implements ITest
{
        private HashTable<Integer, Integer> hashTable = new HashTable<Integer, Integer>(8);
        private int lastInserted;
        private boolean isEmpty = true;

        @Override
        public boolean test()
        {
                return testSet() && testGet() && testContains() && testEmpty() && testRemove();
        }

        @Override
        public boolean testSet()
        {
                this.lastInserted = ThreadLocalRandom.current().nextInt(0, Integer.MAX_VALUE);
                if (this.hashTable.set(this.lastInserted, this.lastInserted) == this.lastInserted)
                {
                        this.isEmpty = false;
                        return true;
                }
                return false;
        }

        @Override
        public boolean testGet()
        {
                return this.hashTable.get(this.lastInserted) == this.lastInserted;
        }

        @Override
        public boolean testEmpty()
        {
                return this.isEmpty == hashTable.isEmpty();
        }

        @Override
        public boolean testContains()
        {
                return this.hashTable.get(this.lastInserted) == this.lastInserted;
        }

        @Override
        public boolean testRemove()
        {
                return this.hashTable.remove(this.lastInserted);
        }
}

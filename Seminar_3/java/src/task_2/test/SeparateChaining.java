package task_2.test;

import java.util.concurrent.ThreadLocalRandom;
import task_2.impl.separate_chaining.HashTable;
import task_2.interfaces.ITest;

public class SeparateChaining implements ITest
{
        private HashTable<Integer, Integer> hashTable = new HashTable<Integer, Integer>();
        private int lastInserted;
        private boolean isEmpty = true;
        private int input[] = new int[] { 4371, 1323, 6173, 4199, 4344, 9679, 1989 };

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

        @Override
        public void display() 
        {
                for (int i : input)
                        this.hashTable.set(i, i);
                this.hashTable.display();
        }
}

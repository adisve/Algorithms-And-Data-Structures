package task_2;

import task_2.impl.linear_probing.HashTable;

public class Main {
        public static void main(String[] args) {
                HashTable<Integer, Integer> hashTable = new HashTable<Integer, Integer>(8);
                int[] inputs = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
                for (int i : inputs) {
                        hashTable.set(i, i);
                }
                System.out.println(hashTable.get(4371));
                hashTable.remove(4371);
                System.out.println(hashTable.get(4371));
        }
}

package task_2;

import task_2.impl.linear_probing.HashTable;

public class Main {
        public static void main(String[] args) {
                HashTable<Integer, Integer> hashTable = new HashTable<Integer, Integer>(8);
                int[] inputs = {4371, 1323, 6173, 4199, 4344, 9679, 1989};
                for (int i = 0; i < inputs.length; i++)
                        hashTable.set(inputs[i], inputs[i]);
                System.out.println(hashTable.get(4371));
        }
}

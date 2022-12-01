package task_4;

import java.util.Random;

public class Test {
        
        private Josephus josephus = new Josephus();        
        private Random rand = new Random();
        
        public void josephusLinkedList()
        {

                long avg_sum = 0;
                for (int i = 10; i < 100000;)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                long start = System.nanoTime();
                                josephus.linkedList(i, rand.nextInt(100));
                                long end = System.nanoTime();
                                avg_sum += (end - start);
                        }
                        System.out.println("Average time to solve Josephus for [Linked List] implementation, with an input size of "+ i + ": " + avg_sum / 10 + "(ns)");
                        i *= 10;
                        avg_sum = 0;
                }
        }

        public void josephusLinkedListIterator()
        {
                long avg_sum = 0;
                for (int i = 10; i < 100000;)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                long start = System.nanoTime();
                                josephus.linkedListIterator(i, rand.nextInt(100));
                                long end = System.nanoTime();
                                avg_sum += (end - start);
                        }
                        System.out.println("Average time to solve Josephus for [Linked List Iterator] implementation, with an input size of "+ i + ": " + avg_sum / 10 + "(ns)");
                        i *= 10;
                        avg_sum = 0;
                }
        }

        public void josephusArrayList()
        {
                long avg_sum = 0;
                for (int i = 10; i < 100000;)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                long start = System.nanoTime();
                                josephus.arrayList(i, rand.nextInt(100));
                                long end = System.nanoTime();
                                avg_sum += (end - start);
                        }
                        System.out.println("Average time to solve Josephus for [ArrayList] implementation, with an input size of "+ i + ": " + avg_sum / 10 + "(ns)");
                        i *= 10;
                        avg_sum = 0;
                }
        }

        public void josephusArrayListIterator()
        {
                long avg_sum = 0;
                for (int i = 10; i < 100000;)
                {
                        for (int j = 0; j < 10; j++)
                        {
                                long start = System.nanoTime();
                                josephus.arrayListIterator(i, rand.nextInt(100));
                                long end = System.nanoTime();
                                avg_sum += (end - start);
                        }
                        System.out.println("Average time to solve Josephus for [ArrayList Iterator] implementation, with an input size of "+ i + ": " + avg_sum / 10 + "(ns)");
                        i *= 10;
                        avg_sum = 0;
                }
        }
}

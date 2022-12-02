package task_4;

import java.util.Random;

public class Test {
        
        private Josephus josephus = new Josephus();        
        private Random rand = new Random();
        
        public void runJosephusAutomatedLinkedList()
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

        public void runJosephusAutomatedLinkedListIterator()
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

        public void runJosephusAutomatedArrayList()
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

        public void runJosephusAutomatedArrayListIterator()
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

        public void runCustomJosephusInput(int n, int m)
        {
                int time;
                long start;
                long end;

                time = 0;
                start = System.nanoTime();
                josephus.linkedList(n, m);
                end = System.nanoTime();
                time += (end - start);
                System.out.println("Time to solve Josephus for [Linked List] implementation, with an input size of "+ n + ": " + time + "(ns)");
                
                time = 0;
                start = System.nanoTime();
                josephus.linkedListIterator(n, m);
                end = System.nanoTime();
                time += (end - start);
                System.out.println("Time to solve Josephus for [Linked List Iterator] implementation, with an input size of "+ n + ": " + time + "(ns)");

                time = 0;
                start = System.nanoTime();
                josephus.arrayList(n, m);
                end = System.nanoTime();
                time += (end - start);
                System.out.println("Time to solve Josephus for [Array List] implementation, with an input size of "+ n + ": " + time + "(ns)");

                time = 0;
                start = System.nanoTime();
                josephus.arrayListIterator(n, m);
                end = System.nanoTime();
                time += (end - start);
                System.out.println("Time to solve Josephus for [Array List Iterator] implementation, with an input size of "+ n + ": " + time + "(ns)");
        }
}

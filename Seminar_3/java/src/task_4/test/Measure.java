package task_4.test;

import java.util.Random;
import java.util.stream.IntStream;

import task_4.models.AVLTree;
import task_4.models.BinarySearchTree;
import task_4.models.MinHeap;
import task_4.models.RedBlackTree;


public class Measure
{
        private final int CYCLES = 10;
        private final int MAX = 1000000;
        private final Random r = new Random();
        public void run()
        {
                measureAVLTreeInsert();
                measureHeapInsert();
                measureBSTreeInsert();
                measureRBTreeInsert();
        }

        private void measureAVLTreeInsert()
        {
                
                int[] randomNumbers = IntStream
                        .generate(() -> r.nextInt(100))
                        .limit(MAX)
                        .toArray();
                float avg_sum;

                for (int i = 10; i < MAX; i *= 10)
                {
                        AVLTree avlTree = new AVLTree();
                        avg_sum = 0;
                        for (int j = 0; j < CYCLES; j++)
                        {
                                for (int k = 0; k < i; k++)
                                {
                                        long start = System.nanoTime();
                                        avlTree.insert(avlTree.root, randomNumbers[k]);
                                        long end = System.nanoTime() - start;
                                        avg_sum += (end * 1000000);
                                }
                        }
                        System.out.println("[AVL Tree] [Input: " + i + "] Average time for insertion (ns): " + avg_sum / CYCLES);
                }
        }

        private void measureBSTreeInsert()
        {
                int[] randomNumbers = IntStream
                        .generate(() -> r.nextInt(100))
                        .limit(MAX)
                        .toArray();
                float avg_sum;

                for (int i = 10; i < MAX; i *= 10)
                {
                        BinarySearchTree heap = new BinarySearchTree();
                        avg_sum = 0;
                        for (int j = 0; j < CYCLES; j++)
                        {
                                for (int k = 0; k < i; k++)
                                {
                                        long start = System.nanoTime();
                                        heap.insert(randomNumbers[k]);
                                        long end = System.nanoTime() - start;
                                        avg_sum += (end * 1000000);
                                }
                        }
                        System.out.println("[BST] [Input: " + i + "] Average time for insertion (ns): " + avg_sum / CYCLES);
                }
        }

        private void measureHeapInsert()
        {
                int[] randomNumbers = IntStream
                        .generate(() -> r.nextInt(100))
                        .limit(MAX)
                        .toArray();
                float avg_sum;

                for (int i = 10; i < MAX; i *= 10)
                {
                        MinHeap heap = new MinHeap();
                        avg_sum = 0;
                        for (int j = 0; j < CYCLES; j++)
                        {
                                for (int k = 0; k < i; k++)
                                {
                                        long start = System.nanoTime();
                                        heap.insert(randomNumbers[k]);
                                        long end = System.nanoTime() - start;
                                        avg_sum += (end * 1000000);
                                }
                        }
                        System.out.println("[MinHeap] [Input: " + i + "] Average time for insertion (ns): " + avg_sum / CYCLES);
                        avg_sum = 0;                                                 
                }
        }

        private void measureRBTreeInsert()
        {
                int[] randomNumbers = IntStream
                        .generate(() -> r.nextInt(100))
                        .limit(MAX)
                        .toArray();
                float avg_sum;

                for (int i = 10; i < MAX; i *= 10)
                {
                        RedBlackTree<Integer> heap = new RedBlackTree<>();
                        avg_sum = 0;
                        for (int j = 0; j < CYCLES; j++)
                        {
                                for (int k = 0; k < i; k++)
                                {
                                        long start = System.nanoTime();
                                        heap.insert(randomNumbers[k]);
                                        long end = System.nanoTime() - start;
                                        avg_sum += (end * 1000000);
                                }
                        }
                        System.out.println("[RBT] [Input: " + i + "] Average time for insertion (ns): " + avg_sum / CYCLES);
                }
        }
}

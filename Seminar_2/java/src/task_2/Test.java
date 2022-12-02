package task_2;

import task_2.structures.OneQueueStack;
import task_2.structures.OneStackQueue;
import task_2.structures.TwoQueueStack;
import task_2.structures.TwoStackQueue;

public class Test {

        private TwoStackQueue<Integer> twoStackQueue = new TwoStackQueue<Integer>();
        private OneStackQueue<Integer> oneStackQueue = new OneStackQueue<Integer>();
        private TwoQueueStack<Integer> twoQueueStack = new TwoQueueStack<Integer>(3);
        private OneQueueStack<Integer> oneQueueStack = new OneQueueStack<Integer>(3);

        public void testTwoStackQueue()
        {
                System.out.println();
                System.out.println("---- TWO STACK QUEUE ----");
                twoStackQueue.enqueue(1);
                twoStackQueue.enqueue(2);
                twoStackQueue.enqueue(3);
                System.out.println("Initial size: " + twoStackQueue.size());
                System.out.println("Peek: " + twoStackQueue.peek());
                System.out.println(twoStackQueue.dequeue());
                System.out.println(twoStackQueue.dequeue());
                System.out.println(twoStackQueue.dequeue());
                System.out.println("Final size: " + twoStackQueue.size());
        }

        public void testOneStackQueue()
        {
                System.out.println();
                System.out.println("---- ONE STACK QUEUE ----");
                oneStackQueue.enqueue(1);
                oneStackQueue.enqueue(2);
                oneStackQueue.enqueue(3);
                System.out.println("Initial size: " + oneStackQueue.size());
                System.out.println("Peek: " + oneStackQueue.peek());
                System.out.println(oneStackQueue.dequeue());
                System.out.println(oneStackQueue.dequeue());
                System.out.println(oneStackQueue.dequeue());
                System.out.println("Final size: " + oneStackQueue.size());
        }

        public void testTwoQueueStack()
        {
                System.out.println();
                System.out.println("---- TWO QUEUE STACK ----");
                twoQueueStack.push(1);
                twoQueueStack.push(2);
                twoQueueStack.push(3);
                System.out.println("Initial size: " + twoQueueStack.size());
                System.out.println("Peek: " + twoQueueStack.top());
                twoQueueStack.pop();
                System.out.println("Peek: " + twoQueueStack.top());
                twoQueueStack.pop();
                System.out.println("Peek: " + twoQueueStack.top());
                twoQueueStack.pop();
                System.out.println("Final size: " + twoQueueStack.size());
        }

        public void testOneQueueStack()
        {
                System.out.println();
                System.out.println("---- ONE QUEUE STACK ----");
                oneQueueStack.push(1);
                oneQueueStack.push(2);
                oneQueueStack.push(3);
                System.out.println("Initial size: " + oneQueueStack.size());
                System.out.println("Peek: " + oneQueueStack.top());
                oneQueueStack.pop();
                System.out.println("Peek: " + oneQueueStack.top());
                oneQueueStack.pop();
                System.out.println("Peek: " + oneQueueStack.top());
                oneQueueStack.pop();
                System.out.println("Final size: " + oneQueueStack.size());
        }
}

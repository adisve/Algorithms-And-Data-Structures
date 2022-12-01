package task_2;

public class Main {
    public static void main(String[] args) {
        testTwoStackQueue();
        testOneStackQueue();
        testTwoQueueStack();
        testOneQueueStack();
    }

    private static void testTwoStackQueue()
    {
        System.out.println();
        System.out.println("---- TWO STACK QUEUE ----");
        TwoStackQueue<Integer> q = new TwoStackQueue<Integer>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        System.out.println("Initial size: " + q.size());
        System.out.println("Peek: " + q.peek());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println("Final size: " + q.size());
    }

    private static void testOneStackQueue()
    {
        System.out.println();
        System.out.println("---- ONE STACK QUEUE ----");
        OneStackQueue<Integer> q = new OneStackQueue<Integer>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        System.out.println("Initial size: " + q.size());
        System.out.println("Peek: " + q.peek());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println(q.dequeue());
        System.out.println("Final size: " + q.size());
    }

    private static void testTwoQueueStack()
    {
        System.out.println();
        System.out.println("---- TWO QUEUE STACK ----");
        TwoQueueStack<Integer> s = new TwoQueueStack<Integer>(3);
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println("Initial size: " + s.size());
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Final size: " + s.size());
    }

    private static void testOneQueueStack()
    {
        System.out.println();
        System.out.println("---- ONE QUEUE STACK ----");
        OneQueueStack<Integer> s = new OneQueueStack<Integer>(3);
        s.push(1);
        s.push(2);
        s.push(3);
        System.out.println("Initial size: " + s.size());
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Peek: " + s.peek());
        s.pop();
        System.out.println("Final size: " + s.size());
    }
}
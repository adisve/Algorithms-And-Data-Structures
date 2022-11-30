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
        System.out.println("---- TWO STACK QUEUE ----");
        TwoStackQueue q = new TwoStackQueue();
        q.add(1);
        q.add(2);
        q.add(3);

        System.out.println(q.remove());
        System.out.println(q.remove());
        System.out.println(q.remove());
        System.out.println(q.remove());
    }

    private static void testOneStackQueue()
    {
        System.out.println("---- ONE STACK QUEUE ----");
        OneStackQueue queue = new OneStackQueue();
        queue.add(1);
        queue.add(2);
        queue.add(3);

        System.out.println(queue.remove());
        System.out.println(queue.remove());
    }

    private static void testTwoQueueStack()
    {
        System.out.println("---- TWO QUEUE STACK ----");
        TwoQueueStack stack = new TwoQueueStack();
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());
    }

    private static void testOneQueueStack()
    {
        System.out.println("---- ONE QUEUE STACK ----");
        OneQueueStack stack = new OneQueueStack();
        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());
        stack.pop();
        System.out.println(stack.top());
    }
}
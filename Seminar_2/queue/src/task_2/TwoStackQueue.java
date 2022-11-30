package task_2;

import java.util.Stack;

class TwoStackQueue {
    private Stack<Integer> first = new Stack<Integer>();
    private Stack<Integer> second = new Stack<Integer>();

    public void add(int i)
    {
        while (!first.isEmpty())
        {
            second.push(first.pop());
        }
        first.push(i);
        while (!second.isEmpty()) {
            first.push(second.pop());
        }
    }

    public int remove()
    {
        if (first.isEmpty())
        {
            System.out.println("Queue contains no elements");
            System.exit(0);
        }
        int i = first.peek();
        first.pop();
        return i;
    }
}

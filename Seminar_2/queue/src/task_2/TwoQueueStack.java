package task_2;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class TwoQueueStack {

    private int ERROR = -1;

    private Queue<Integer> first = new LinkedList<Integer>();
    private Queue<Integer> second = new LinkedList<Integer>();


    public void push(int i)
    {
        second.add(i);
        while (!first.isEmpty())
        {
            second.add(first.peek());
            first.remove();
        }
        swap();
    }


    public void pop()
    {
        if (first.isEmpty())
            return;

        first.remove();
    }

    public int top()
    {
        if (first.isEmpty())
            return ERROR;

        return first.peek();
    }

    public void swap()
    {
        Queue<Integer> temp = first;
        first = second;
        second = temp;
    }
}

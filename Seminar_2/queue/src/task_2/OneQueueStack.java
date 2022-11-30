package task_2;

import java.util.LinkedList;
import java.util.Queue;

class OneQueueStack {
    private int ERROR = -1;
    private Queue<Integer> queue = new LinkedList<Integer>();

    public void push(int i)
    {
        int prevSize = queue.size();
        queue.add(i);

        for (int j = 0; j < prevSize; j++)
        {
            int temp = queue.remove();
            queue.add(temp);
        }
    }

    public int pop()
    {
        if (queue.isEmpty())
        {
            System.out.println("Stack contains no elements");
            return ERROR;
        }
        int i = queue.remove();
        return i;
    }

    public int top()
    {
        if (queue.isEmpty())
            return ERROR;
        return queue.peek();
    }
}

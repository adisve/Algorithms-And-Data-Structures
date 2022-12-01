package task_2;

import java.util.Stack;

class TwoStackQueue<T> {
    private Stack<T> first = new Stack<>();
    private Stack<T> second = new Stack<>();

    
    /** 
     * @param i -> Element to add
     */
    public void enqueue(T i)
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

    
    /** 
     * @return T -> Element to remove
     */
    public T dequeue()
    {
        if (first.isEmpty() && second.isEmpty())
        {
            System.out.println("Queue contains no elements");
            System.exit(0);
        }
        else if (second.isEmpty() && !first.isEmpty())
        {
            Stack<T> temp = first;
            first = second;
            second = temp;
        }
        return second.pop();
    }

    
    /** 
     * @return T -> Element to consume
     */
    public T peek()
    {
        if (first.isEmpty())
            return null;
        return first.lastElement();
    }

    
    /** 
     * @return int -> Size of stack
     */
    public int size()
    {
        return first.size() + second.size();
    }
}

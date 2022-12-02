package task_2.structures;

import java.util.LinkedList;
import java.util.Queue;

public class TwoQueueStack<T> {

    private int capacity;
    private int size;
    private Queue<T> first = new LinkedList<T>();
    private Queue<T> second = new LinkedList<T>();

    public TwoQueueStack(int capacity)
    {
        this.capacity = capacity;
    }

    
    /** 
     * @param i -> Element to add
     * @throws StackOverflowError
     */
    public void push(T i) throws StackOverflowError
    {
        if (this.size == this.capacity)
            throw new StackOverflowError("Stack overflow error - max capacity reached for stack of size " + this.capacity);
        this.second.add(i);
        while (!this.first.isEmpty())
        {
            this.second.add(first.peek());
            this.first.remove();
        }
        this.swap();
        this.size++;
            
    }


    
    /** 
     * @throws StackUnderFlowError
     */
    public T pop() throws StackUnderFlowError
    {
        if (this.first.isEmpty())
            throw new StackUnderFlowError("Stack underflow error - illegal memory location"); 
        this.size--;
        return this.first.remove();
    }

    
    /** 
     * @return T -> Element to consume
     */
    public T top()
    {
        if (this.first.isEmpty())
            return null;

        return this.first.peek();
    }

    
    /** 
     * @return int -> Size of stack
     */
    public int size()
    {
        return this.first.size() + this.second.size();
    }

    /**
     * Swaps the two available stacks
     */
    private void swap()
    {
        Queue<T> temp = this.first;
        this.first = this.second;
        this.second = temp;
    }
}

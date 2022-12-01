package task_2;

import java.util.LinkedList;
import java.util.Queue;

class OneQueueStack<T> {

    private int size;
    private int capacity;
    private Queue<T> queue = new LinkedList<T>();

    public OneQueueStack(int capacity)
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
        
        int prevSize = this.queue.size();
        this.queue.add(i);

        T temp;
        for (int j = 0; j < prevSize; j++)
        {
            temp = queue.remove();
            this.queue.add(temp);
        }
        this.size++;
    }

    
    /** 
     * @return T -> Element to remove
     * @throws StackOverflowError
     */
    public T pop() throws StackUnderFlowError
    {
        if (this.queue.isEmpty())
            throw new StackUnderFlowError("Stack underflow error - illegal memory location");
        this.size--;
        return this.queue.remove();
    }

    
    /** 
     * @return T -> Element to consume
     */
    public T peek()
    {
        if (this.queue.isEmpty())
            return null;
        return this.queue.peek();
    }

    
    /** 
     * @return int -> Size of stack
     */
    public int size()
    {
        return this.queue.size();
    }
}

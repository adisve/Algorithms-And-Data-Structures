package task_2;

import java.util.Stack;

class OneStackQueue<T> {

    private Stack<T> stack = new Stack<T>();

    
    /** 
     * @param i -> Element to add
     */
    public void enqueue(T i)
    {
        stack.push(i);
    }

    
    /** 
     * Pop all the elements from task_2.Main Stack recursively until Stack size is equal to 1,
     * then push all popped elements back onto the stack
     * @return T -> Element to remove
     */
    
    public T dequeue()
    {
        if (stack.isEmpty())
            return null;

        // No need to recurse if stack only contains one element
        if (stack.size() == 1)
            return stack.pop();

        T i = stack.pop();
        T recursiveValue = dequeue();
        stack.push(i);
        return recursiveValue;
    }

    
    /** 
     * @return int -> Size of queue
     */
    public int size()
    {
        if (stack.isEmpty())
            return 0;
        return stack.size();
    }

    
    /** 
     * @return T -> Element to consume
     */
    public T peek()
    {
        if (stack.isEmpty())
            return null;
        return stack.firstElement();
    }
}

package task_2;

import java.util.Stack;

class OneStackQueue {
    private int ERROR = -1;
    private Stack<Integer> stack = new Stack<Integer>();

    public void add(int i)
    {
        stack.push(i);
    }

    // Pop all the elements from task_2.Main Stack recursively until Stack size is equal to 1,
    // then push all popped elements back onto the stack
    public int remove()
    {
        if (stack.isEmpty())
            return ERROR;

        // No need to recurse if stack only contains one element
        if (stack.size() == 1)
            return stack.pop();

        int i = stack.pop();
        int recursiveValue = remove();
        stack.push(i);
        return recursiveValue;
    }
}

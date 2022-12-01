package task_3.structures;

import task_3.models.Node;

/**
 * Custom linked list for specific use
 */
public class LinkedList<T> {

    private Node<T> head;
    
    /** 
     * @param i
     * @return int -> Whether node was added or not
     */
    public int add(T i)
    {
        Node<T> newNode = new Node<T>(i);
        if (this.head == null)
            this.head = newNode;
            
        else {
            Node<T> lastNode = this.head;
            while (lastNode.next != null)
            {
                lastNode = lastNode.next;
            }
            lastNode.next = newNode;
        }
        return 1;
    }

    
    /** 
     * @param index
     * @return int -> Whether node was removed or not
     */
    public int remove(int index)
    {
        Node<T> currNode = this.head;
        Node<T> prevNode = null;

        if (currNode != null && index == 0)
        {
            this.head = currNode.next;
            return 1;
        }

        int counter = 1;
        while (currNode != null && counter != index)
        {
            prevNode = currNode;
            currNode = currNode.next;
        }

        if (currNode != null)
        {
            prevNode.next = currNode.next;
            return 1;
        }
        return 0;
    }

    
    /** 
     * @param index
     * @return Node
     */
    public Node<T> elementAt(int index)
    {
        if (this.head == null)
            return null;

        int counter = 0;
        Node<T> tempNode = this.head;
        while(tempNode != null)
        {
            if (counter == index)
                return tempNode;
            counter++;
            tempNode = tempNode.next;
        }
        return null;
    }

    
    /** 
     * @return int -> Size of linked list
     */
    public int size()
    {
        int size = 0;
        Node<T> tempNode = this.head;
        
        while (tempNode != null)
        {
            size++;
            tempNode = tempNode.next;
        }
        return size;
    }
}

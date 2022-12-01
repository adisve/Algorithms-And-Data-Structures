package task_4;

public class CircularLinkedList<T> {

    Node<T> head;
    Node<T> tail;

    
    /** 
     * @param data -> Generic type data added
     * to a nodes .data property
     */
    public void add(T data)
    {
        Node<T> newNode = new Node<>(data);

        if (this.head == null) {
            this.head = newNode;
        }
        else {
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.tail.next = this.head;
    }

    
    /** 
     * @param index -> Index to refer to in removal
     */
    public void removeAt(T index)
    {
        Node<T> currNode = this.head;

        if (this.head == null)
            System.out.println("No node at index " + index);
        else
        {
            do {
                Node<T> nextNode = currNode.next;
                if (nextNode.data.equals(index)) {
                    if (this.tail == this.head) {
                        head = null;
                        this.tail = null;
                    } else {
                        currNode.next = nextNode.next;
                        if (this.head == nextNode) {
                            this.head = this.head.next;
                        }
                        if (this.tail == nextNode) {
                            this.tail = currNode;
                        }
                    }
                    break;
                }
                currNode = nextNode;
            } while (currNode != this.head);
        }
    }

    
    /** 
     * @return int -> Size of linked list
     */
    public int size()
    {
        Node<T> currNode = head;
        int size = 0;

        if (head != null) {
            do {
                size++;
                currNode = currNode.next;
            } while (currNode != this.head);
        }
        return size;
    }

    
    /** 
     * @param index
     * @return Node<T>
     */
    public Node<T> elementAt(int index) {
        if(index > this.size()){
            return null;
        }
        Node<T> n = head;
        int counter = 0;
        while(counter != index){
            n = n.next;
            counter++;
        }
        return n;
    }
}

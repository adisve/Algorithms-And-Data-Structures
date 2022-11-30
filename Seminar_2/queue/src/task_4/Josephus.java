package task_4;

import java.util.ArrayList;

public class Josephus {
    public void linkedList(int n, int m)
    {
        int start = 0;
        int index;
        CircularLinkedList<Integer> circularLinkedList = fillLinkedList(n);

        while (circularLinkedList.size() > 1)
        {
            index = (start + m) % circularLinkedList.size();
            circularLinkedList.deleteByValue(circularLinkedList.elementAt(index).data);
            start = index;
        }
        System.out.println("Final node: " + circularLinkedList.head.data);
    }
    public void linkedListIterator(int n , int m)
    {
        
    }

    public void arrayList(int n, int m)
    {

    }

    public void arrayListIterator(int n, int m)
    {

    }



    private static CircularLinkedList<Integer> fillLinkedList(int n)
    {
        CircularLinkedList<Integer> linkedList = new CircularLinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            linkedList.insert(i+1);
        }
        return linkedList;
    }

    private static ArrayList<Integer> fillArrayList(int n)
    {
        ArrayList<Integer> arrayList = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            arrayList.add(i+1);
        }
        return arrayList;
    }
}

package task_4;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class Josephus {

    public void linkedList(int n, int m)
    {
        int index = 0;
        CircularLinkedList<Integer> circularLinkedList = fillCircularLinkedList(n);

        while (circularLinkedList.size() > 1)
        {
            index = (index + m) % circularLinkedList.size();
            circularLinkedList.removeAt(circularLinkedList.elementAt(index).data);
        }
        System.out.println("[CircularLinkedList] Final node: " + circularLinkedList.head.data);
    }

    public void linkedListIterator(int n , int m)
    {
        LinkedList<Integer> linkedList = fillLinkedList(n);
        Iterator<Integer> iterator;
        int index = 0;

        while (linkedList.size() > 1) {
            iterator = linkedList.iterator();
            index = (index + m) % linkedList.size();
            for (int i = 0; i < index; i++) {
                iterator.next();
            }
            iterator.next();
            iterator.remove();
        }
        System.out.println("[LinkedList] Final node: " + linkedList.getFirst());
    }

    public void arrayList(int n, int m)
    {
        ArrayList<Integer> arrayList = fillArrayList(n);
        int index = 0;

        while (arrayList.size() > 1)
        {
            index = (index + m) % arrayList.size();
            arrayList.remove(index);
        }
        System.out.println("[ArrayList] Final node: " + arrayList.get(0));
    }

    public void arrayListIterator(int n, int m)
    {
        ArrayList<Integer> arrayList = fillArrayList(n);
        Iterator<Integer> iterator;
        int index = 0;

        while (arrayList.size() > 1) {
            iterator = arrayList.iterator();
            index = (index + m) % arrayList.size();
            for (int i = 0; i < index; i++) {
                iterator.next();
            }
            iterator.next();
            iterator.remove();
        }
        System.out.println("[LinkedList] Final node: " + arrayList.get(0));
    }



    private static CircularLinkedList<Integer> fillCircularLinkedList(int n)
    {
        CircularLinkedList<Integer> linkedList = new CircularLinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            linkedList.add(i+1);
        }
        return linkedList;
    }

    private static LinkedList<Integer> fillLinkedList(int n)
    {
        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        for (int i = 0; i < n; i++) {
            linkedList.add(i+1);
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
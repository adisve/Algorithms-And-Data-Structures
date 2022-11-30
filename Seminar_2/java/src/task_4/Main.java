package task_4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Josephus josephus = new Josephus();
        Scanner in = new Scanner(System.in);

        System.out.print("N >> ");
        int n = in.nextInt();
        System.out.println();
        System.out.print("M >> ");
        int m = in.nextInt();

        josephus.linkedList(n, m);
        josephus.linkedListIterator(n, m);
        josephus.arrayList(n, m);
        josephus.arrayListIterator(n, m);
        in.close();
    }
}

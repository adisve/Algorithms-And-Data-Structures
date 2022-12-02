package task_4;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Test test = new Test();
        Scanner in = new Scanner(System.in);
        boolean loop = true;

        while (loop)
        {
            System.out.println();
            System.out.println("1. Test running time for input 10 - 100000");
            System.out.println("2. Input your own value for the Josephus problem (n and m)");
            System.out.println("3. Exit");
            System.out.print("-> ");
            switch (in.nextLine())
            {
                case "1" -> 
                {
                    test(test);
                }
                case "2" ->
                {
                    customInput(in, test);
                }
                case "3" ->
                {
                    loop = false;
                    break;
                }
            }
        }
        in.close();
    }

    static void test(Test test)
    {
        test.runJosephusAutomatedLinkedList();
        test.runJosephusAutomatedLinkedListIterator();
        test.runJosephusAutomatedArrayList();
        test.runJosephusAutomatedArrayListIterator();
    }

    static void customInput(Scanner in, Test test)
    {
        System.out.print("N -> ");
        int n = Integer.parseInt(in.nextLine());
        System.out.print("M -> ");
        int m = Integer.parseInt(in.nextLine());
        test.runCustomJosephusInput(n, m);
    }
}

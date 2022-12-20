package task_2;

import task_2.test.LinearProbing;
import task_2.test.QuadraticProbing;
import task_2.test.SeparateChaining;

public class Main
{
        public static void main(String[] args)
        {
                LinearProbing linearProbing = new LinearProbing();
                QuadraticProbing quadraticProbing = new QuadraticProbing();
                SeparateChaining separateChaining = new SeparateChaining();

                System.out.println("Linear probing test: " + (linearProbing.test() ? "Passed" : "Failed"));
                System.out.println("Quadratic probing test: " + (quadraticProbing.test() ? "Passed" : "Failed"));
                System.out.println("Linear probing test: " + (separateChaining.test() ? "Passed" : "Failed"));
        
                System.out.println("\n\nHash table using linear probing:");
                linearProbing.display();
                System.out.println("\n\nHash table using quadratic probing:");
                quadraticProbing.display();
                System.out.println("\n\nHash table using separate chaining:");
                separateChaining.display();
        }
}
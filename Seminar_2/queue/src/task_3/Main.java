package task_3;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        boolean loop = true;
        AddressBook addressBook = new AddressBook();
        while (loop)
        {
            System.out.println("1. Add contact");
            System.out.println("2. Remove contact");
            System.out.println("3. Find contacts by index search");
            System.out.println("4. Display all contacts");
            System.out.println("5. Exit");

            Scanner in = new Scanner(System.in);
            System.out.print(">> ");
            switch (in.nextLine()) {
                case "1" -> {
                    System.out.print("Contact name: ");
                    String newContactName = in.nextLine();
                    System.out.print("Contact address: ");
                    String newContactAddress = in.nextLine();
                    System.out.println();
                    addressBook.add(new Contact(newContactName, newContactAddress));
                }
                case "2" -> {
                    System.out.print("Contact name to delete: ");
                    String deleteContactName = in.nextLine();
                    System.out.println();
                    addressBook.remove(deleteContactName);
                }
                case "3" -> {
                    System.out.print("Contact index: ");
                    int findIndex = in.nextInt();
                    System.out.println();
                    addressBook.get(findIndex);
                }
                case "4" -> addressBook.show();
                case "5" -> loop = false;
            }
        }
    }
}

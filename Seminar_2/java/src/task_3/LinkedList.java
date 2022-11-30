package task_3;

import java.util.Objects;

public class LinkedList {
    private ContactNode head;

    public void insert(Contact contact)
    {
        ContactNode newContactNode = new ContactNode(contact);
        if (this.head == null)
        {
            this.head = newContactNode;
        }
        else {
            ContactNode lastNode = this.head;
            while (lastNode.nextNode != null)
            {
                lastNode = lastNode.nextNode;
            }
            lastNode.nextNode = newContactNode;
        }
    }

    public void remove(String contactName)
    {
        ContactNode currContactNode = this.head;
        ContactNode prevContactNode = null;

        if (currContactNode != null && Objects.equals(currContactNode.contact.name, contactName))
        {
            this.head = currContactNode.nextNode;
            System.out.printf("Removed user %s", contactName);
            System.out.println();
        }
        while (currContactNode != null && !Objects.equals(currContactNode.contact.name, contactName))
        {
            prevContactNode = currContactNode;
            currContactNode = currContactNode.nextNode;
        }

        if (currContactNode != null)
        {
            assert prevContactNode != null;
            prevContactNode.nextNode = currContactNode.nextNode;
            System.out.printf("Removed user %s", contactName);
            System.out.println();
        }
        if (currContactNode == null)
        {
            System.out.printf("User '%s' not found in address book", contactName);
            System.out.println();
        }
    }

    public ContactNode find(int index)
    {
        if (this.head == null)
        {
            System.out.println("Address book is empty");
            System.out.println();
            return null;
        }

        // Try to find contact by index
        int counter = 0;
        ContactNode tempNode = this.head;
        while(tempNode != null)
        {
            if (counter == index)
            {
                System.out.printf("Contact found at index %d", index);
                System.out.println();
                System.out.printf("Name: %s", tempNode.contact.name);
                System.out.println();
                System.out.printf("Address: %s", tempNode.contact.address);
                System.out.println();
                System.out.println();
                return tempNode.nextNode;
            }
            counter++;
            tempNode = tempNode.nextNode;
        }
        System.out.printf("No contact found at index %d", index);
        return null;
    }

    public void display()
    {
        ContactNode tempNode = this.head;

        if (tempNode == null)
        {
            System.out.println("Address book is empty");
            System.out.println();
            return;
        }

        System.out.println("Address book users:");
        while(tempNode != null)
        {
            System.out.println("\n");
            System.out.printf("Name: %s", tempNode.contact.name);
            System.out.println();
            System.out.printf("Address: %s", tempNode.contact.address);
            System.out.println("\n");
            tempNode = tempNode.nextNode;
        }
    }
}

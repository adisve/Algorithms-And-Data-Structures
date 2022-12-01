package task_3;

/**
 * Abstract wrapper class for using custom Linked list
 * as address book container.
 */
class AddressBook {

    private LinkedList<Contact> linkedList = new LinkedList<Contact>();

    
    /** 
     * @param contact -> Contact to add
     */
    public void add(Contact contact)
    { 
        if (this.linkedList.add(contact) == 1)
            System.out.println("\nAdded " + contact.name + " to address book\n");
        else
            System.out.println("\nCould not add " + contact.name + " to address book" + "\n");
    }

    
    /** 
     * @param index -> Index to refer to in removal
     */
    public void removeContact(int index) 
    { 
        if (this.linkedList.remove(index) == 1)
            System.out.println("\nSuccessfully deleted contact at index " + index + "\n");
        else
            System.out.println("\nNo contact found at index " + index + "\n");
    }

    
    /** 
     * @param index -> Index to refer to in search
     */
    public void findContact(int index)
    {
        Node<Contact> contactNode = this.linkedList.elementAt(index);

        if (contactNode != null)
        {
            System.out.println("Contact found at index " + index + "\n");
            System.out.println("Name: " + contactNode.data.name);
            System.out.println("Address: " + contactNode.data.address + "\n");
            return;
        }    
        
        System.out.println("\nNo contact found at index " + index + "\n");
    }

    /**
     * Displays all available contacts in the address book
     */
    public void show()
    { 
        int linkedListSize = linkedList.size();
        if (linkedListSize == 0)
        {
            System.out.println("\nAddress book is empty\n");
        }
        else 
        {
            for (int i = 0; i < linkedListSize; i++)
            {
                Node<Contact> cNode = linkedList.elementAt(i);
                System.out.println("---------------------------------");
                System.out.println("Contact index: " + i);
                System.out.println("Name: " + cNode.data.name);
                System.out.println("Address: " + cNode.data.address);
                System.out.println("---------------------------------");
                System.out.println();
            }
        }
    }

}

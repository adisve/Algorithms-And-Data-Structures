package task_3;


class AddressBook {
    private LinkedList addressBook = new LinkedList();

    public void add(Contact contact) { this.addressBook.insert(contact); }

    public void remove(String contactName) { this.addressBook.remove(contactName); }

    public ContactNode get(int index) { return this.addressBook.find(index); }

    public void show() { this.addressBook.display(); }

}

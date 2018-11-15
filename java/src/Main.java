import LinkedList.*;

public class Main {
    public static void main(String[] args) {
        DoublyLinkedList<Integer> linkedList = new DoublyLinkedList<Integer>();
        linkedList.add(1);
        linkedList.add(2);
        linkedList.add(3);
        linkedList.add(4);
        linkedList.remove(0);
        System.out.println(linkedList.toList());
    }
}

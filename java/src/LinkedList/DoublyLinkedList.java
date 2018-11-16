package LinkedList;

public class DoublyLinkedList<Type> extends LinkedList<Type> {
    @Override
    public void add(Type item) {
        if (head == null) {
            head = new Node<>(item);
        } else {
            Node<Type> last = head;
            while (last.getNext() != null) {
                last = last.getNext();
            }
            Node<Type> current = new Node<>(item);
            last.setNext(current);
            current.setBack(last);
        }
        size++;
    }

    @Override
    public void remove(int index) {
        if (index + 1 > size) throw new IndexOutOfBoundsException();
        Node<Type> current = head;
        Node<Type> last = null;
        Node<Type> next;
        for (int i = 0; i < index; i++) {
            last = current;
            current = current.getNext();
        }
        next = current.getNext();
        if (last == null) {
            head = next;
            head.setBack(null);
        } else {
            if (current == head) {
                head = head.getNext();
            }
            last.setNext(next);
            if (next != null)
                next.setBack(last);
        }
        current.setBack(null);
        current.setNext(null);
        current.setData(null);
        size--;
    }

    @Override
    public void clear() {
        if (head == null) return;
        Node<Type> last = head, current;
        while (last.getNext() != null) {
            current = last;
            last = last.getNext();
            current.setData(null);
            current.setNext(null);
            current.setBack(null);
        }
        last.setData(null);
        last.setNext(null);
        last.setBack(null);
        head = null;
        size = 0;
    }
}

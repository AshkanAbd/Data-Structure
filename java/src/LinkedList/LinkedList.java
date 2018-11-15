package LinkedList;

import java.util.*;

public class LinkedList<Type> {
    protected Node<Type> head;
    protected int size;

    public LinkedList() {
        this.head = null;
        size = 0;
    }

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
        }
        size++;
    }

    public Node<Type> getNode(int index) {
        if (index + 1 > size) throw new IndexOutOfBoundsException();
        Node<Type> last = head;
        for (int i = 0; i < index; i++) {
            last = last.getNext();
        }
        return last;
    }

    public Type get(int index) {
        if (index + 1 > size) throw new IndexOutOfBoundsException();
        Node<Type> last = head;
        for (int i = 0; i < index; i++) {
            last = last.getNext();
        }
        return last.getData();
    }

    public int IndexOf(Type item) {
        Node<Type> current = head;
        for (int i = 0; i < size; i++) {
            if (current.getData().equals(item)) return i;
            current = current.getNext();
        }
        return -1;
    }

    public int IndexOf(Type item, int start) {
        Node<Type> current = head;
        for (int i = start; i < size; i++) {
            if (current.getData().equals(item)) return i;
            current = current.getNext();
        }
        return -1;
    }

    public void remove(int index) {
        if (index + 1 > size) throw new IndexOutOfBoundsException();
        Node<Type> current = head;
        Node<Type> last = null;
        Node<Type> next = null;
        for (int i = 0; i < index; i++) {
            last = current;
            current = current.getNext();
        }
        next = current.getNext();
        if (last == null) {
            head = next;
        } else {
            last.setNext(next);
        }
    }

    public void addAll(Type[] items) {
        for (Type item : items)
            this.add(item);
    }

    public List<Type> toList() {
        List<Type> list = new ArrayList<>();
        Node<Type> last = head;
        list.add(last.getData());
        while (last.getNext() != null) {
            last = last.getNext();
            list.add(last.getData());
        }
        return list;
    }

    public Type[] toArray() {
        return (Type[]) toList().toArray();
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("[");
        Node<Type> node = head;
        builder.append(node.getData());
        while (node.getNext() != null) {
            node = node.getNext();
            builder.append(", ");
            builder.append(node.getData());
        }
        builder.append(']');
        return builder.toString();
    }
}

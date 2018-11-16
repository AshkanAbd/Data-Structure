package LinkedList;

import java.util.*;

public class CircleLinkedList<Type> extends LinkedList<Type> {

    @Override
    public void add(Type item) {
        if (head == null) {
            head = new Node<>(item);
            head.setNext(head);
        } else {
            Node<Type> last = head;
            while (last.getNext() != head) {
                last = last.getNext();
            }
            Node<Type> current = new Node<>(item);
            last.setNext(current);
            current.setNext(head);
        }
        size++;
    }

    @Override
    public void clear() {
        if (head == null) return;
        Node<Type> last = head, current;
        while (last.getNext() != head) {
            current = last;
            last = last.getNext();
            current.setData(null);
            current.setNext(null);
        }
        last.setNext(null);
        last.setData(null);
        head = null;
        size = 0;
    }

    @Override
    public Type get(int index) {
        Node<Type> last = head;
        for (int i = 0; i < index; i++) {
            last = last.getNext();
        }
        return last.getData();
    }

    @Override
    public Node<Type> getNode(int index) {
        Node<Type> last = head;
        for (int i = 0; i < index; i++) {
            last = last.getNext();
        }
        return last;
    }

    @Override
    public void remove(int index) {
        Node<Type> current = head;
        Node<Type> last = null;
        Node<Type> next;
        for (int i = 0; i < index; i++) {
            last = current;
            current = current.getNext();
        }
        next = current.getNext();
        if (last == null) {
            this.getNode(size - 1).setNext(next);
            head = next;
        } else {
            last.setNext(next);
        }
        current.setNext(null);
        current.setData(null);
        size--;
    }

    @Override
    public List<Type> toList() {
        List<Type> list = new ArrayList<>();
        if (head == null) return list;
        Node<Type> last = head;
        list.add(last.getData());
        while (last.getNext() != head) {
            last = last.getNext();
            list.add(last.getData());
        }
        return list;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("[");
        if (head != null) {
            Node<Type> node = head;
            builder.append(node.getData());
            while (node.getNext() != head) {
                node = node.getNext();
                builder.append(", ");
                builder.append(node.getData());
            }
        }
        builder.append(']');
        return builder.toString();
    }
}

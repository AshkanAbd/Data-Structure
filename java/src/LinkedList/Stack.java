package LinkedList;

public class Stack<Type> {
    private Node<Type> head;
    private int size;

    public Stack() {
        this.head = null;
        size = 0;
    }

    public void push(Type item) {
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

    public Type peek() {
        if (head == null) return null;
        Node<Type> current = head;
        while (current.getNext() != null) {
            current = current.getNext();
        }
        return current.getData();
    }

    public Type pop() {
        if (head == null) return null;
        Node<Type> last = null;
        Node<Type> current = head;
        while (current.getNext() != null) {
            last = current;
            current = current.getNext();
        }
        size--;
        if (last == null) {
            Type t = head.getData();
            head.setData(null);
            head = null;
            return t;
        } else {
            last.setNext(null);
            Type t = current.getData();
            current.setData(null);
            return t;
        }
    }

    public int search(Type item, int start) {
        Node<Type> current = head;
        for (int i = start; i < size; i++) {
            if (current.getData().equals(item)) return i;
            current = current.getNext();
        }
        return -1;
    }

    public void clear() {
        if (head == null) return;
        Node<Type> last = head, current;
        while (last.getNext() != null) {
            current = last;
            last = last.getNext();
            current.setData(null);
            current.setNext(null);
        }
        head = null;
        last.setNext(null);
        last.setData(null);
        size = 0;
    }

    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder("[");
        if (head != null) {
            Node<Type> node = head;
            builder.append(node.getData());
            while (node.getNext() != null) {
                node = node.getNext();
                builder.append(", ");
                builder.append(node.getData());
            }
        }
        builder.append(']');
        return builder.toString();
    }
}

package LinkedList;

public class Queue<Type> {
    private Node<Type> head;
    private int size;

    public Queue() {
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

    public Type peek() {
        if (head == null) return null;
        return head.getData();
    }

    public Type poll() {
        if (head == null) return null;
        Type t = head.getData();
        head = head.getNext();
        return t;
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

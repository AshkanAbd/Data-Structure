package LinkedList;

public class Node<Type> {
    private Type data;
    private Node<Type> next;
    private Node<Type> back;

    public Node(Type data, Node<Type> next, Node<Type> back) {
        this.data = data;
        this.next = next;
        this.back = back;
    }

    public Node(Type data) {
        this.data = data;
        this.next = null;
        this.back = null;
    }

    public Node() {
        this.data = null;
        this.next = null;
        this.back = null;
    }

    public Node(Type data, Node<Type> next) {
        this.data = data;
        this.next = next;
        this.back = null;
    }

    public Type getData() {
        return data;
    }

    public void setData(Type data) {
        this.data = data;
    }

    public Node<Type> getNext() {
        return next;
    }

    public void setNext(Node<Type> next) {
        this.next = next;
    }

    public Node<Type> getBack() {
        return back;
    }

    public void setBack(Node<Type> back) {
        this.back = back;
    }

    @Override
    public int hashCode() {
        return data.hashCode() + next.hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Node))
            return false;
        Node node = (Node) obj;
        return next == node.next && data.equals(node.data);
    }
}

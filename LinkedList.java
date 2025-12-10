public class LinkedList {
    private static class Node {
        int data;
        Node next;
        Node(int d) { data = d; }
    }

    private Node head;

    public LinkedList() { head = null; }

    public void create(int[] vals) {
        head = null;
        for (int v : vals) insert(v);
    }

    public void insert(int value) {
        Node node = new Node(value);
        if (head == null) { head = node; return; }
        Node cur = head;
        while (cur.next != null) cur = cur.next;
        cur.next = node;
    }

    public boolean delete(int value) {
        Node cur = head, prev = null;
        while (cur != null) {
            if (cur.data == value) {
                if (prev == null) head = cur.next;
                else prev.next = cur.next;
                return true;
            }
            prev = cur;
            cur = cur.next;
        }
        return false;
    }

    public void traverse() {
        System.out.print("[");
        Node cur = head;
        boolean first = true;
        while (cur != null) {
            if (!first) System.out.print(", ");
            System.out.print(cur.data);
            first = false;
            cur = cur.next;
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.create(new int[]{1,2,3});
        System.out.print("After create: "); ll.traverse();
        ll.insert(4);
        System.out.print("After insert 4: "); ll.traverse();
        boolean removed = ll.delete(2);
        System.out.println("Deleted 2? " + (removed ? "yes" : "no"));
        System.out.print("Final list: "); ll.traverse();
    }
}

public class LinkedList {
    private static class Node {
        String title;
        String author;
        double rating;
        Node next;
        Node(String t, String a, double r) { title = t; author = a; rating = r; next = null; }
    }

    private static class Book {
        String title; String author; double rating;
        Book(String t, String a, double r) { title = t; author = a; rating = r; }
    }

    private Node head;

    public LinkedList() { head = null; }

    public void create(Book[] books) {
        head = null;
        for (Book b : books) insert(b.title, b.author, b.rating);
    }

    public void insert(String title, String author, double rating) {
        Node node = new Node(title, author, rating);
        if (head == null) { head = node; return; }
        Node cur = head;
        while (cur.next != null) cur = cur.next;
        cur.next = node;
    }

    public boolean delete(String title) {
        Node cur = head, prev = null;
        while (cur != null) {
            if (cur.title.equals(title)) {
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
        Node cur = head;
        int i = 1;
        if (cur == null) {
            System.out.println("(no books in the list)");
            return;
        }
        while (cur != null) {
            System.out.println(i + ". " + cur.title + " by " + cur.author + " - Rating: " + cur.rating);
            cur = cur.next;
            i++;
        }
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        Book[] sample = new Book[] {
            new Book("The Hobbit", "J.R.R. Tolkien", 4.8),
            new Book("1984", "George Orwell", 4.6),
            new Book("To Kill a Mockingbird", "Harper Lee", 4.7)
        };
        ll.create(sample);
        System.out.println("Books after create:"); ll.traverse();
        ll.insert("Dune", "Frank Herbert", 4.5);
        System.out.println();
        System.out.println("After inserting 'Dune':"); ll.traverse();
        boolean removed = ll.delete("1984");
        System.out.println();
        System.out.println("Deleted '1984'? " + (removed ? "yes" : "no"));
        System.out.println();
        System.out.println("Final list:"); ll.traverse();
    }
}

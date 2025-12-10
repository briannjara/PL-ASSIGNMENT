class Node:
    def __init__(self, title, author, rating):
        self.title = title
        self.author = author
        self.rating = rating
        self.next = None

    def __repr__(self):
        return f"Node({self.title!r}, {self.author!r}, {self.rating})"


class LinkedList:
    def __init__(self):
        self.head = None

    def create(self, iterable=None):
        """Create the list from an iterable of books.

        Each item in iterable can be a tuple (title, author, rating),
        a list with three items, or a dict with keys 'title','author','rating'.
        """
        self.head = None
        if iterable:
            for item in iterable:
                if isinstance(item, dict):
                    t = item.get('title')
                    a = item.get('author', '')
                    r = item.get('rating', 0)
                    self.insert(t, a, r)
                elif isinstance(item, (tuple, list)) and len(item) >= 3:
                    t, a, r = item[0], item[1], item[2]
                    self.insert(t, a, r)
                else:
                    # treat as title only
                    self.insert(item, '', 0)

    def insert(self, title, author, rating):
        """Insert a book at the end of the list."""
        node = Node(title, author, rating)
        if self.head is None:
            self.head = node
            return
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = node

    def delete(self, title):
        """Delete first book that matches the `title`. Return True if deleted."""
        cur = self.head
        prev = None
        while cur:
            if cur.title == title:
                if prev is None:
                    self.head = cur.next
                else:
                    prev.next = cur.next
                return True
            prev = cur
            cur = cur.next
        return False

    def traverse(self):
        """Return a list of books as dicts in traversal order."""
        books = []
        cur = self.head
        while cur:
            books.append({'title': cur.title, 'author': cur.author, 'rating': cur.rating})
            cur = cur.next
        return books

    def print_books(self):
        """Print each book in a readable format."""
        cur = self.head
        i = 1
        if cur is None:
            print("(no books in the list)")
            return
        while cur:
            print(f"{i}. {cur.title} by {cur.author} - Rating: {cur.rating}")
            cur = cur.next
            i += 1


if __name__ == "__main__":
    # simple demo of the book linked list
    ll = LinkedList()
    sample = [
        ("The Hobbit", "J.R.R. Tolkien", 4.8),
        ("1984", "George Orwell", 4.6),
        ("To Kill a Mockingbird", "Harper Lee", 4.7),
    ]
    ll.create(sample)
    print("Books after create:")
    ll.print_books()

    ll.insert("Dune", "Frank Herbert", 4.5)
    print("\nAfter inserting 'Dune':")
    ll.print_books()

    removed = ll.delete("1984")
    print(f"\nDeleted '1984'? {removed}")
    print("\nFinal list:")
    ll.print_books()

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def create(self, iterable=None):
        """Create a list from an iterable (or empty list if None)."""
        self.head = None
        if iterable:
            for v in iterable:
                self.insert(v)

    def insert(self, data):
        """Insert at the end of the list."""
        node = Node(data)
        if self.head is None:
            self.head = node
            return
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = node

    def delete(self, data):
        """Delete first occurrence of data. Returns True if deleted."""
        cur = self.head
        prev = None
        while cur:
            if cur.data == data:
                if prev is None:
                    self.head = cur.next
                else:
                    prev.next = cur.next
                return True
            prev = cur
            cur = cur.next
        return False

    def traverse(self):
        """Return a list of node data in traversal order."""
        vals = []
        cur = self.head
        while cur:
            vals.append(cur.data)
            cur = cur.next
        return vals


if __name__ == "__main__":
    ll = LinkedList()
    ll.create([1, 2, 3])
    print("After create:", ll.traverse())
    ll.insert(4)
    print("After insert 4:", ll.traverse())
    removed = ll.delete(2)
    print("Deleted 2?", removed)
    print("Final list:", ll.traverse())

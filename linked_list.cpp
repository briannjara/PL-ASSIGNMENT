#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList(): head(nullptr) {}
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    void create(const std::vector<int>& vals) {
        head = nullptr;
        for (int v : vals) insert(v);
    }

    void insert(int value) {
        Node* node = new Node(value);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    bool deleteValue(int value) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur) {
            if (cur->data == value) {
                if (!prev) head = cur->next;
                else prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    void traverse() const {
        Node* cur = head;
        bool first = true;
        std::cout << "[";
        while (cur) {
            if (!first) std::cout << ", ";
            std::cout << cur->data;
            first = false;
            cur = cur->next;
        }
        std::cout << "]\n";
    }
};

int main() {
    LinkedList ll;
    ll.create({1, 2, 3});
    std::cout << "After create: "; ll.traverse();
    ll.insert(4);
    std::cout << "After insert 4: "; ll.traverse();
    bool removed = ll.deleteValue(2);
    std::cout << "Deleted 2? " << (removed ? "yes" : "no") << "\n";
    std::cout << "Final list: "; ll.traverse();
    return 0;
}

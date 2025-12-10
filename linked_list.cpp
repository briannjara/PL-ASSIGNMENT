#include <iostream>
#include <vector>
#include <tuple>
#include <string>

struct Node {
    std::string title;
    std::string author;
    double rating;
    Node* next;
    Node(const std::string& t, const std::string& a, double r) : title(t), author(a), rating(r), next(nullptr) {}
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

    void create(const std::vector<std::tuple<std::string,std::string,double>>& books) {
        head = nullptr;
        for (const auto &b : books) insert(std::get<0>(b), std::get<1>(b), std::get<2>(b));
    }

    void insert(const std::string& title, const std::string& author, double rating) {
        Node* node = new Node(title, author, rating);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    bool deleteValue(const std::string& title) {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur) {
            if (cur->title == title) {
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
        int i = 1;
        if (!cur) {
            std::cout << "(no books in the list)\n";
            return;
        }
        while (cur) {
            std::cout << i << ". " << cur->title << " by " << cur->author << " - Rating: " << cur->rating << "\n";
            cur = cur->next;
            ++i;
        }
    }
};

int main() {
    LinkedList ll;
    std::vector<std::tuple<std::string,std::string,double>> sample = {
        std::make_tuple(std::string("The Hobbit"), std::string("J.R.R. Tolkien"), 4.8),
        std::make_tuple(std::string("1984"), std::string("George Orwell"), 4.6),
        std::make_tuple(std::string("To Kill a Mockingbird"), std::string("Harper Lee"), 4.7),
    };
    ll.create(sample);
    std::cout << "Books after create:\n"; ll.traverse();
    ll.insert("Dune", "Frank Herbert", 4.5);
    std::cout << "\nAfter inserting 'Dune':\n"; ll.traverse();
    bool removed = ll.deleteValue("1984");
    std::cout << "\nDeleted '1984'? " << (removed ? "yes" : "no") << "\n";
    std::cout << "Final list:\n"; ll.traverse();
    return 0;
}

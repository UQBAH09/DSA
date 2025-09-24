#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

class CircularLL {
    Node* head;
    Node* tail;

    void relink() { 
        if (tail) tail->next = head; 
    }

    void clear() {
        if (!head) return;
        tail->next = nullptr;
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }

public:
    CircularLL() : head(nullptr), tail(nullptr) {}

    ~CircularLL() { clear(); }

    // i) insert at end
    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = tail = n;
            relink();
            return;
        }
        tail->next = n;
        tail = n;
        relink();
    }

    // ii) insert at beginning
    void insertBeginning(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = tail = n;
            relink();
            return;
        }
        n->next = head;
        head = n;
        relink();
    }

    // iii) insert at given position
    void insertAt(int x, int pos) {
        if (pos <= 0 || !head) { insertBeginning(x); return; }
        Node* cur = head;
        int i = 0;
        while (i < pos - 1 && cur->next != head) {
            cur = cur->next;
            ++i;
        }
        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        if (cur == tail) tail = n;
        relink();
    }

    // iv) delete node 
    bool deleteValue(int x) {
        if (!head) return false;

        if (head == tail) {
            if (head->val == x) {
                delete head;
                head = tail = nullptr;
                return true;
            }
            return false;
        }

        if (head->val == x) {
            Node* old = head;
            head = head->next;
            delete old;
            relink();
            return true;
        }

        Node* prev = head;
        Node* cur = head->next;
        while (cur != head) {
            if (cur->val == x) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                relink();
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    // v) print LL
    void print() const {
        if (!head) { 
            cout << "List: (empty)" << endl; 
            return; 
        }
        cout << "List: ";
        const Node* cur = head;
        do {
            cout << cur->val << " ";
            cur = cur->next;
        } while (cur != head);
        cout << endl;
    }
};

int main() {
    CircularLL cll;

    cll.insertEnd(2);
    cll.insertEnd(3);
    cll.insertEnd(5);
    cll.insertBeginning(1);
    cll.insertAt(4, 3);
    cll.insertAt(0, 0);
    cll.insertAt(6, 100);

    cll.print();

    cll.deleteValue(0);
    cll.deleteValue(6);
    cll.deleteValue(3);
    cll.print();
}

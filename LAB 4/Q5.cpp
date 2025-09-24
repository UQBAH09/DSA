// Q3 of Lab 3
#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val = 0): val(val), next(NULL), prev(NULL) {}
};

class LL{
    Node *head;
    Node *tail;

    void linkCircle() {
        if (head && tail) {
            head->prev = tail;
            tail->next = head;
        }
    }

    void breakCircleForClear() {
        if (head && tail) {
            tail->next = nullptr;
            head->prev = nullptr;
        }
    }

    int length() const {
        if (!head) return 0;
        int len = 0;
        const Node* cur = head;
        do {
            ++len;
            cur = cur->next;
        } while (cur != head);
        return len;
    }

    void clear(){
        if (!head) { tail = nullptr; return; }
        breakCircleForClear();
        Node *cur = head;
        while (cur) {
            Node *nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
    }

public:
    LL(): head(NULL), tail(NULL){}

    ~LL(){ clear(); }

    // Insert at beginning
    void addFirst(int item){
        Node *newNode = new Node(item);
        if(!head){
            head = tail = newNode;
            linkCircle();
            return;
        }
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }

    // Insert at position
    void addPos(int item, int pos){
        if (!head || pos <= 0) { addFirst(item); return; }
        int n = length();
        if (pos >= n) { add(item); return; }

        Node *cur = head;
        for (int i = 0; i < pos - 1; ++i) cur = cur->next;

        Node *newNode = new Node(item);
        Node *after = cur->next;
        newNode->next = after;
        newNode->prev = cur;
        cur->next = newNode;
        after->prev = newNode;
    }

    // Insert at end
    void add(int item, int pos = -1){
        if(!head || pos == 0){
            addFirst(item);
            return;
        }
        else if (pos != -1){
            addPos(item, pos);
            return;
        }
        Node *newNode = new Node(item);
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }

    // Print LL
    void display(){
        if (!head) { cout << "List: (empty)\n"; return; }
        cout << "List: ";
        Node *temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void removeFirst(){
        if (!head) return;
        if (head == tail){
            delete head;
            head = tail = nullptr;
            return;
        }
        Node *old = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete old;
    }

    void removeLast(){
        if (!tail) return;
        if (head == tail){
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node *old = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete old;
    }

    // Delete node
    bool remove(int item){
        if (!head) return false;

        if (head->val == item){
            removeFirst();
            return true;
        }
        if (tail->val == item){
            removeLast();
            return true;
        }

        Node *cur = head->next;
        while (cur != head){
            if (cur->val == item){
                Node *L = cur->prev;
                Node *R = cur->next;
                L->next = R;
                R->prev = L;
                delete cur;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

int main(){
    LL list1;

    list1.add(65);
    list1.add(10);
    list1.add(15, 1);
    list1.add(20, 0);
    list1.addFirst(99);
    list1.addPos(77, 2);
    list1.display();

    list1.remove(99);
    list1.remove(10);
    list1.remove(65);
    list1.remove(12345);
    list1.display();
}

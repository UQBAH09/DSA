#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(int val): val(val), next(NULL) {}
};

class SingleLL{
    Node* head;
    Node* tail;
public:
    SingleLL(): head(NULL), tail(NULL) {}

    void addFirst(int val){
        Node* node = new Node(val);
        if(head == NULL){
            head = node;
        }
        else{
            node->next = head;
            head = node;
        }
    }

    void addMiddle(int val, int pos){
        Node* node = new Node(val);
        Node* cur = head;
        Node* next;

        for (int i = 0; i < pos-1; i++)
        {
            cur = cur->next;
        }

        next = cur->next;
        cur->next = node;
        node->next = next;
    }

    void addLast(int val){
        Node* node = new Node(val);
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = tail;
    }

    void delFirst(){
        Node* temp = head;
        head = temp->next;

        delete temp;
    }

    void delEnd(){
        Node* pre = head;
        Node* cur = head->next;

        while (cur->next != NULL)
        {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = NULL;
        delete cur;
    }
};
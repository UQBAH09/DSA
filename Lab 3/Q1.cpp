#include<iostream>
using namespace std;

class Node{
    int val;
    Node *next;
public:
    Node(int val): val(val), next(NULL) {}

    // Getter
    const void setVal(int v){val = v;}
    const void setNext(Node *node) {next = node;}
    // Setter
    int getVal(){ return val;}
    Node* getNext(){return next;}

    ~Node(){next = NULL;}
};

class LL{
    Node *head;
    Node *tail;
public:
    LL(): head(NULL), tail(NULL) {}

    ~LL(){
        while(head->getNext() != NULL){
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }
        head = NULL;
        tail = NULL;
    }

    void addFirst(int val){
        Node* newNode = new Node(val);
        
        // If the list is empty
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        // If the list has items
        else{
            newNode->setNext(head);
            head = newNode;
        }
    }

    void add(int val = 0, int pos = -1){
        // Insertion at end
        if(pos == -1){
            // If the list has no items
            if(head == NULL){
                addFirst(val);
            }
            // Inserting at end;
            else{
                Node* newNode = new Node(val);

                tail->setNext(newNode);
                tail = newNode;
            }
        }
        // Insertion at a specific index
        else{
            Node *newNode = new Node(val);
            Node *temp = head;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
        }
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->getVal();
            temp = temp->getNext();
            if(temp) cout << " => ";
        }
    }

    void sortEvenOdd(){
        if (!head || !head->getNext()) return;

        Node* curr = head;
        Node* prev = head;
        Node* even = NULL;
        Node* temp = NULL;

        while (curr != NULL)
        {
            if(curr->getVal() % 2 == 0){    // If the current is even
                temp = curr;
                curr = curr->getNext();

                if(even == NULL){   // If it is the first even number then set the temp to curr and make current move 1 forward
                    temp->setNext(head);
                    head = temp;
                }
                else{   // else just set teh link to  point to the last even number
                    temp->setNext(even->getNext());
                    even->setNext(temp);
                }
                // repair the link by seting the next to the prevous
                prev->setNext(curr);
                even = temp;
            }
            else{
                prev = curr;
                curr = curr->getNext();
            }
        }
        tail = prev;
    }

    void getTaleVal(){
        cout << "\n\n" << tail->getVal() << endl;
    }
};

int main(){
    LL num;
    num.add(0);
    num.add(9);
    num.add(6);
    num.add(2);
    num.add(3);
    num.add(8);
    num.add(1);
    num.add(7);

    cout << "Orignal array: ";
    num.display();

    cout << "\nSeprated array: ";
    num.sortEvenOdd();
    num.display();
}
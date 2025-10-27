#include <iostream>
#include <string>
#include <random>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float score;
};

struct Node {
    Student data;
    Node* left;
    Node* right;

    Node(Student s) : data(s), left(nullptr), right(nullptr) {}
};

class StudentBST {
private:
    Node* root;

    Node* insert(Node* node, Student s) {
        if (!node) return new Node(s);
        if (s.name < node->data.name)
            node->left = insert(node->left, s);
        else if (s.name > node->data.name)
            node->right = insert(node->right, s);
        return node;
    }

    Node* search(Node* node, const string& name) {
        if (!node || node->data.name == name) return node;
        if (name < node->data.name)
            return search(node->left, name);
        else
            return search(node->right, name);
    }

    Node* deleteLowScore(Node* node) {
        if (!node) return nullptr;

        node->left = deleteLowScore(node->left);
        node->right = deleteLowScore(node->right);

        if (node->data.score < 10) {
            Node* temp = nullptr;
            if (!node->left) {
                temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data.name);
            }
        }
        return node;
    }

    Node* deleteNode(Node* node, const string& name) {
        if (!node) return nullptr;
        if (name < node->data.name)
            node->left = deleteNode(node->left, name);
        else if (name > node->data.name)
            node->right = deleteNode(node->right, name);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* successor = findMin(node->right);
                node->data = successor->data;
                node->right = deleteNode(node->right, successor->data.name);
            }
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right)
            node = node->right;
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << "Name: " << node->data.name << ", Roll: " << node->data.rollNumber << ", Score: " << node->data.score << endl;
        inorder(node->right);
    }

public:
    StudentBST() : root(nullptr) {}

    void insert(Student s) {
        root = insert(root, s);
    }

    void search(const string& name) {
        Node* result = search(root, name);
        if (result)
            cout << "Found: " << result->data.name << ", Roll: " << result->data.rollNumber << ", Score: " << result->data.score << endl;
        else
            cout << "Student not found.\n";
    }

    void deleteLowScore() {
        root = deleteLowScore(root);
    }

    void getMaxStudent() {
        Node* maxNode = findMax(root);
        if (maxNode)
            cout << "Max Student: " << maxNode->data.name << ", Roll: " << maxNode->data.rollNumber << ", Score: " << maxNode->data.score << endl;
        else
            cout << "Tree is empty.\n";
    }

    void display() {
        inorder(root);
    }
};

int main() {
    srand(time(0));
    StudentBST bst;

    Student students[10] = {
        {"Alice", 101, 95},
        {"Bob", 102, 8},
        {"Charlie", 103, 85},
        {"David", 104, 5},
        {"Eve", 105, 70},
        {"Frank", 106, 60},
        {"Grace", 107, 45},
        {"Heidi", 108, 30},
        {"Ivan", 109, 15},
        {"Judy", 110, 90}
    };
    
    for (int i = 0; i < 6; i++)
    {
        int n = rand() % 10;
        bst.insert(students[n]);

    }

    cout << "\nAll Students:\n";
    bst.display();

    cout << "\nSearching for 'Charlie':\n";
    bst.search("Charlie");

    cout << "\nDeleting students with score < 10...\n";
    bst.deleteLowScore();

    cout << "\nAll Students after deletion:\n";
    bst.display();

    cout << "\nStudent with max name:\n";
    bst.getMaxStudent();

    return 0;
}
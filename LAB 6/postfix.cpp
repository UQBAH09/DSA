#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* arr;
    int top;
    int capacity;

    void resize() {
        capacity *= 2;
        char* newArr = new char[capacity];
        for (int i = 0; i <= top; ++i)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    Stack() {
        capacity = 10;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top + 1 == capacity)
            resize();
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Precedence function
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convert infix to postfix
string infixToPostfix(const string& infix) {
    Stack s;
    string postfix;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop(); // remove '('
        } else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek()))
                postfix += s.pop();
            s.push(c);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
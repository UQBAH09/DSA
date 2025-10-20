#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int capacity;
    int size;
    public:
    Queue(int c) {
        capacity = c;
        arr = new int[capacity];
        size = 0;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == capacity;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        arr[size] = value;
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++)
        {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
   
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

int main(){
    Queue que(3);

    que.enqueue(10);
    que.enqueue(20);
    que.enqueue(30);
    cout << "Front: " << que.getFront() << endl;

    que.dequeue();
    cout << "Front: " << que.getFront() << endl;
     cout << "Rear: " << que.getRear() << endl;

    que.enqueue(40);

    return 0;
}
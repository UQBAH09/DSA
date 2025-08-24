#include<iostream>
using namespace std;

class Box{
    int *num;
public:
    Box(int n = 0) {
        num = new int (n);
    }

    // Deep-Copy Constructor
    Box (const Box &b): num(new int (*b.num)) {}

    // Deep-Copy Assignment Constructor
    Box& operator=(const Box& b) {
        if (this != &b) {
            int* n = new int(*b.num);
            delete num;
            num = n;
        }
        return *this;
    }

    int getnum() {return *num;}

    ~Box(){
        delete[] num;
    }
};

int main(){
    Box box1(30);
    Box box2 = box1;
    Box box3(10);
    box3 = box1;

    cout << "Value of box 1:" << box1.getnum() << endl;
    cout << "Value of box 2:" << box2.getnum() << endl;
    cout << "Value of box 3:" << box3.getnum() << endl;
}
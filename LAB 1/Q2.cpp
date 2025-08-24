#include<iostream>
#include<cstring>
using namespace std;

class Exam{
    char *name;
    char *date;
    double score;
public:
    Exam(char* n = "", char* d = "", double s = 0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        date = new char[strlen(d) + 1];
        strcpy(date, d);
        score = s;
    }

    void setName(char *n){
        delete[] name;
        name = new char(strlen(n) + 1);
        strcpy(name, n);
    }

    void setDate(char *d){
        delete[] date;
        date = new char(strlen(d) + 1);
        strcpy(date, d);
    }

    void setScore(double s){score = s;}

    void detail(){
        cout << "Name: " << name << ", Date: " << date << ", Score: " << score << endl;
    }

    ~Exam(){
        delete[] name;
        delete[] date;
    }
};

int main() {
    Exam e1("Bob", "2025-08-23", 95.5);
    cout << "Original exam-1 details:" << endl;
    e1.detail();


    Exam e2 = e1;
    cout << "\nShallow copied exam-2 details:" << endl;
    e2.detail();

    e2.setName("Tom");
    e2.setDate("2025-09-01");
    e2.setScore(97.2);

    cout << "\nAfter modifying exam2:" << endl;
    e2.detail();

    cout << "\nCheck exam1 details after modifying exam2:" << endl;
    e1.detail();

    return 0;
}
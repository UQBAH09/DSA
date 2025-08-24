#include<iostream>
using namespace std;

class Bank{
    double balance;
public:
    Bank(): balance(0) {}
    Bank(double intialBalance): balance(intialBalance) {}
    Bank(const Bank &b): balance(b.balance) {}

    double getBalance() {return balance;}

    void withdraw(double amount) {
        if(amount > balance){
            cout << "Insufficent balance." << endl;
            return;
        }
        balance -= amount;
        cout << "Amount successfuly withdrawn." << endl;
    }
};

int main(){
    Bank account1;
    cout << "Total balance of account 1: $" << account1.getBalance() << endl;

    Bank account2(1000);
    cout << "Total balance of account 2: $" << account2.getBalance() << endl;

    Bank account3 = account2;
    account3.withdraw(200);
    cout << "Total balance of account 2: $" << account2.getBalance() << endl;
    cout << "Total balance of account 3: $" << account3.getBalance() << endl;
}
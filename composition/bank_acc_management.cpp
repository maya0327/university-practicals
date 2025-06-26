#include <iostream>
using namespace std;

class BankAcc {
private:
    int balance;
    int pin;

public:
    int id;
    int enteredPin;

    BankAcc(int p, int initialBalance) {
        pin = p;
        balance = initialBalance;
    }

    bool checkPin(int entered) {
        return entered == pin;
    }

    void getBalance() {
        if (checkPin(enteredPin)) {
            cout << "User ID: " << id << endl;
            cout << "Balance: " << balance << endl;
        } else {
            cout << "Invalid PIN!" << endl;
        }
    }

    void deposit(int amount) {
        if (checkPin(enteredPin)) {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid PIN!" << endl;
        }
    }

    void withdraw(int amount) {
        if (checkPin(enteredPin) && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        } else {
            cout << "Invalid PIN or insufficient balance!" << endl;
        }
    }
};

int main() {
    // Create an account with PIN 1234 and balance of 10,000
    BankAcc b1(1234, 10000);
    b1.id = 676767;

    cout << "Enter PIN to view balance: ";
    cin >> b1.enteredPin;

    b1.getBalance();

    cout << "Enter amount to deposit: ";
    int depAmount;
    cin >> depAmount;
    b1.deposit(depAmount);

    cout << "Enter amount to withdraw: ";
    int wdrAmount;
    cin >> wdrAmount;
    b1.withdraw(wdrAmount);

    b1.getBalance();

    return 0;
}

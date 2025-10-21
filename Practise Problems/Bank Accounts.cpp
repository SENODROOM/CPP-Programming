#include <iostream>
using namespace std;

int main() {
    int choice;
    int balance = 0;

    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n2. Withdraw\n-1. Quit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            int deposit;
            cout << "Enter amount to deposit: ";
            cin >> deposit;
            if (deposit > 0) {
                balance += deposit;
                cout << "Deposited: " << deposit << endl;
            } else {
                cout << "Invalid deposit amount.\n";
            }
            cout << "Current balance: " << balance << endl;
        }
        else if (choice == 2) {
            int withdraw;
            cout << "Enter amount to withdraw: ";
            cin >> withdraw;
            if (withdraw > balance)
                cout << "Insufficient balance!\n";
            else if (withdraw > 0) {
                balance -= withdraw;
                cout << "Withdrawn: " << withdraw << endl;
            } else {
                cout << "Invalid withdrawal amount.\n";
            }
            cout << "Current balance: " << balance << endl;
        }
        else if (choice != -1) {
            cout << "Invalid option!\n";
        }

    } while (choice != -1);

    cout << "Final balance = " << balance << endl;
    return 0;
}
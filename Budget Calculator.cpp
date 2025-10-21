#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double income, rent, groceries, utilities, transportation, entertainment , other;
    
    // Input Expenses:
    cout << "Enter your monthly income: ";
    cin >> income;
    
    cout << "Enter amount spent on Rent: ";
    cin >> rent;
    cout << "Enter amount spent on Groceries: ";
    cin >> groceries;
    cout << "Enter amount spent on Utilities: ";
    cin >> utilities;
    cout << "Enter amount spent on Transportation: ";
    cin >> transportation;
    cout << "Enter amount spent on Entertainment: ";
    cin >> entertainment;
    cout << "Enter amount spent on Other expenses: ";
    cin >> other;

    // TOTAL:
    double totalExpenses = rent + groceries + utilities + transportation + entertainment + other;
    double balance = income - totalExpenses;

    // BUDGET SUMMARY:
    cout << fixed << setprecision(2);
    cout << "\nBUDGET SUMMARY:\n";
    cout << "Total Income: " << income << endl;
    cout << "Total Expenses: " << totalExpenses << endl;
    cout << "Remaining Balance: " << balance << endl;

    // EXPENSES PERCENTAGE:
    cout << "\nEXPENSES PERCENTAGE:\n";
    cout << "Rent: " << (rent / income) * 100 << "%" << endl;
    cout << "Groceries: " << (groceries / income) * 100 << "%" << endl;
    cout << "Utilities: " << (utilities / income) * 100 << "%" << endl;
    cout << "Transportation: " << (transportation / income) * 100 << "%" << endl;
    cout << "Entertainment: " << (entertainment / income) * 100 << "%" << endl;
    cout << "Other: " << (other / income) * 100 << "%" << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;
float error(float expense)
{

    do
    {
        cout << "Invalid Input......" << endl;
        cout << "Enter again :";
        cin >> expense;
    } while (expense < 0);
    return expense;
}
float percentage(float price, float income)
{
    float per;
    per = (price / income) * 100;
    return per;
}

int main()
{

    float income, rent, groceries, utilities, entertainment, transport, other, balance, expenses;
    do
    {
        cout << "\t----------Personal Budget Manager----------\n";
        cout << "Total income :";
        cin >> income;
        if (income < 0)
        {
            income = error(income);
        }
        cout << "\t\"Expenses\"" << endl;
        cout << "Groceries: ";
        cin >> groceries;
        if (groceries < 0 || groceries > income)
        {
            groceries = error(groceries);
        }
        cout << "Rent: ";
        cin >> rent;
        if (rent < 0 || rent > income)
        {
            rent = error(rent);
        }

        cout << "Utilities: ";
        cin >> utilities;
        if (utilities < 0 || utilities > income)
        {
            utilities = error(utilities);
        }
        cout << "Entertainment: ";
        cin >> entertainment;
        if (entertainment < 0 || entertainment > income)
        {
            entertainment = error(entertainment);
        }
        cout << "Transport: ";
        cin >> transport;
        if (transport < 0 || transport > income)
        {
            transport = error(transport);
        }
        cout << "Other: ";
        cin >> other;
        if (other < 0 || other > income)
        {
            other = error(other);
        }
        cout << "\t\"Percentage of Expenses\"" << endl;
        cout << "Groceries: " << percentage(groceries, income) << endl;
        cout << "Entertainment: " << percentage(entertainment, income) << endl;
        cout << "Rent: " << percentage(rent, income) << endl;
        cout << "Transport: " << percentage(transport, income) << endl;
        cout << "Utilities: " << percentage(utilities, income) << endl;
        cout << "Other: " << percentage(other, income) << endl;
        expenses = groceries + utilities + other + entertainment + transport + rent;
        cout << "\t\"Total Budget\"" << endl;
        cout << "Total Expenses : " << expenses << endl;
        if (expenses > income)
        {
            cout << "Invalid ( Expenses should must be less than income )" << endl;
        }
    } while (expenses > income);
    balance = income - expenses;
    cout << "Remaining Balance : " << balance << endl;
    cout << "\t----------End----------";

    return 0;
}

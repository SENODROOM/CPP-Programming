#include <iostream>
using namespace std;
int main()
{
    int coffee, cups;
    cout << "Which Coffee do you want? Type 1 for Espresso, 2 for Cappuccino, and 3 for Latte: ";
    cin >> coffee;
    cout << "Nummber of Cups: ";
    cin >> cups;
    char sugar, creem;
    cout << "Do you want extra Sugar (Rs. 20)? [y/n]: ";
    cin >> sugar;
    cout << "Do you want extra Whipped Creem (Rs. 30)? [y/n]: ";
    cin >> creem;
    int total = 0;
    if (coffee == 1)
    {
        total += 150;
    }
    else if (coffee == 2)
    {
        total += 180;
    }
    else
    {
        total += 200;
    }
    if (sugar == 'y')
    {
        total += 20;
    }
    if (creem = 'y')
    {
        total += 30;
    }
    cout << total <<endl;
    total *= cups;
    cout <<"Total: "<< total <<endl;
    double tax = total * 0.1;
    cout <<"Tax: "<< tax <<endl;
    double grandtotal = total + tax;
    cout <<"Grand Total: "<< grandtotal;
}
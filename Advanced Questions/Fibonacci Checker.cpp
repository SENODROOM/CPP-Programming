#include<iostream>
#include<iomanip>
using namespace std;

bool isFibonacci(int num, bool check)
{
    int a = 0, b = 1, next = 0;

    if (num == 0 || num == 1)
        return check = true;

    while (next < num) {
        next = a + b;
        a = b;
        b = next;

        if (next == num)
            return check = true;
    }

    return check = false;
}

int main()
{
    int num;
    bool check = true;

    cout << "\t--------Fibonacci Checker---------" << endl;
    cout << "Enter a number: ";
    cin >> num;

    if (num < 0) {
        do{
        cout << "Invalid input! Please enter a non-negative number." << endl;
        cin>> num;
        }while(num < 0);
    } 
    
        if (isFibonacci(num, check))
            cout << num << " is present in Fibonacci Sequence. " << endl;
        else
            cout << num << " is NOT present in Fibonacci Sequence. " << endl;
    

    cout << "\t---------End---------" << endl;
    return 0;
}
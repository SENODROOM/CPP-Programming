#include <iostream>
#include<iomanip>
using namespace std;

bool Factorial(int num, int &n) {
    int fact = 1;
    n = 1;

    while (fact < num) {
        n++;
        fact *= n;
    }

    return fact == num;
}

int main() {
    int num, n;
    cout<<"\t--------Factorial--------"<<endl;
    cout << "Enter a number: ";
    cin >> num;


    if (num <= 0) {
        cout << "Enter a positive number only!" << endl;
        return 0;
    }

    if (Factorial(num, n))
        cout << num << " is the factorial of " << n << endl;
    else
        cout << num << " is not a  factorial of any integer " << endl;
    cout<<"\t--------End---------";

    return 0;
}
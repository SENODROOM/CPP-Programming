#include <iostream>
#include<iomanip>
using namespace std;
int main() {
    int n,sum=0;
    char ch = 'y';
    while (ch == 'y' || ch == 'Y') {
        cout << "Input number" << endl;
        cin >> n;
        sum += n;
        cout << "Press y if you want to enter another number" << endl;
        cin >> ch;
    }
    cout << "Summ of all numbers is " << sum << endl;
}
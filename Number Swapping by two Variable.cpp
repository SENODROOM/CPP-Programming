#include<iostream>
using namespace std;
int main() {
    int a, b;
    cout << "Enter a and b with space" << endl;
    cin >> a >> b;
    cout << "Before swapping " << a << " " << b << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << "After swapping " << a << " " << b << endl;
}
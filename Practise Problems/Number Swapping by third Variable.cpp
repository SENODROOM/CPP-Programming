#include<iostream>
using namespace std;
int main() {
    int a, b, c;
    cout << "Enter a and b with space" << endl;
    cin >> a >> b;
    cout << "Before swapping " << a << " " << b << endl;
    c = a;
    a = b;
    b = c;
    cout << "After swapping " << a << " " << b << endl;
}
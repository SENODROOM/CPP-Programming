#include<iostream>
using namespace std;
int main() {
    int a = 34,b=5,c=4;
    cout << (a && b) << endl;
    cout << (!a && ++b) << endl;
    cout << (!(a > b) || ++c > 10) << endl;
    cout << (!a && ++b) << endl;
    cout << (a > b || ++c < 6) << endl;
    cout << a << b << c << endl;
}
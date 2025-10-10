#include <iostream>
using namespace std;
int main()
{
    // int a = 12,b=7;
    // b = a++; // b=12 a=13
    // int c = --a; // c=12 a=12
    // int d = a++ + c-- + ++b; // 12 + 12 + 13
    // cout << a << b << c << d;

    int a = 5, b = 13, c = 99;
    b = c++;
    cout << b << c;
}
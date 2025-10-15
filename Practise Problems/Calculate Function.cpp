#include <iostream>
using namespace std;
int calcu(int x,int y,int &sub,int &mul,int&div)
{
    sub = x - y;
    mul = x * y;
    div = x / y;
    return x + y;
}
int main()
{
    int a = 10, b = 2;
    int add, su, mu, di;
    add=calcu(a, b, su, mu, di);
    cout << add << " " << su << " " << mu << " " << di;
}
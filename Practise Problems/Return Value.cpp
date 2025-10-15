#include <iostream>
using namespace std;

int fun(int a)
{
    return ++a;//local variable
}
int main()
{
    int a = 10;
    a=fun(a);
    cout << a;
}
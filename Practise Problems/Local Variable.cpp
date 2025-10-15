#include <iostream>
using namespace std;

void fun(int a)
{
    a++;//local variable
}
int main()
{
    int a = 10;
    fun(a);
    cout << a;
}
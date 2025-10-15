#include <iostream>
using namespace std;

void fun(int &x)
{
     ++x;//reference variable
}
int main()
{
    int a = 10;
    fun(a);
    cout << a;
}
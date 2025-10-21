#include <iostream>
using namespace std;
int main()
{
    int a=2;
    int sum=0;
    while (a<=30)
    {
        sum = sum + a;
        a =a+2;
    }
    cout << sum;
}
#include <iostream>
using namespace std;
int main()
{
    int a=3;
    int pro=1;
    while (a<=19)
    {
        pro = pro * a;
        a =a+2;
    }
    cout << pro;
}
#include <iostream>
using namespace std;
int main()
{
    int num = 1;
    cout << "Numbers from 1 to 100" << endl;
    while (num <= 100)
    {
        cout << num << " ";
        num++;
    }

    cout << endl
         << "Numbers from 100 to 1" << endl;
    num--;
    while (num >= 1)
    {
        cout << num << " ";
        num--;
    }

    cout << endl
         << "Numbers of Sequence 1" << endl;
    int num2 = 20;
    while (num2 >= 2)
    {
        cout << num2 << " ";
        num2 = num2 - 2;
    }

    int num3 = 2;
    cout << endl
         << "Numbers of Sequence 2" << endl;
    while (num3 <= 20)
    {
        cout << num3 << " ";
        num3 = num3 + 3;
    }

    int num4 = 99;
    cout << endl
         << "Numbers of Sequence 3" << endl;
    while (num4 >= 0)
    {
        cout << num4 << " ";
        num4 = num4 - 11;
    }
}
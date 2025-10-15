#include <iostream>
using namespace std;
int main()
{
    int line;
    cin >> line;
    for (int i = 1; i <= line; i++)
    {
        for (int s = i; s <= line - 1; s++)
            cout << "*";
        for (int j = 1; j <= i; j++)
            cout << " ";
        for (int j = 2; j <= i; j++)
            cout << " ";
       
        for (int s = i; s <= line - 1; s++)
            cout << "*";
        cout << endl;
    }
    for (int i = line-1; i >=1; i--)
    {
        for (int s = 1; s <= line - i; s++)
            cout << "*";
        for (int j = 1; j <= i; j++)
            cout << " ";
        for (int j = 2; j <= i; j++)
            cout << " ";
        for (int s = 1; s <= line - i; s++)
            cout << "*";
        cout << endl;
    }
}
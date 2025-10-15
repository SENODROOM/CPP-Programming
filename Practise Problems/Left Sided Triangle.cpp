#include <iostream>
using namespace std;
int main()
{
    int line;
    cin >> line;
    for (int i = 1; i <= line; i++)
    {
        for (int s = i; s <= line - 1; s++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

}
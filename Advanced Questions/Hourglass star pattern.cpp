#include <iostream>
using namespace std;
int main()
{
    int n = 0, count = 0;
    cout << "Number of rows: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < (n - i); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " *";
        }
        cout << endl;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < (n - i); j++)
        {
            cout << " ";
        }
        for (int j = 0; j < (i + 1); j++)
        {
            cout << " *";
        }
        cout << endl;
    }
}
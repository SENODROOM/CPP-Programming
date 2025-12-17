#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "[";
    for (int i = 1; i < n + 1; i++)
    {
        if ((i % 3) == 0)
            cout << "FIZZ";
        if ((i % 5) == 0)
            cout << "BUZZ";
        if (!(((i % 3) == 0) || ((i % 5) == 0)))
            cout << i;
        if (i != n)
            cout << ",";
    }
    cout << "]";
    return 0;
}
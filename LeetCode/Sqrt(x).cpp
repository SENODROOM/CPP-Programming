#include <iostream>
using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;

    int i = 1;
    while (i * i <= x)
    {
        i++;
    }
    return i - 1;
}

int main()
{
    int x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Square root = " << mySqrt(x) << endl;
    return 0;
}
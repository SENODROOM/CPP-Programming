#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int binary, decimal = 0, count = 0;
    cout << "Enter a binary number: ";
    cin >> binary;

    while (binary > 0)
    {
        int digit = binary % 10;
        decimal += digit * pow(2, count);
        binary /= 10;
        count++;
    }

    cout << "Decimal equivalent: " << decimal;
    return 0;
}
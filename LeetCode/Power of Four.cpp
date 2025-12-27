#include <iostream>
using namespace std;

bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;
    if (n == 1)
        return true;
    for (int i = 4; i <= n; i *= 4)
    {
        if (i == n)
            return true;
    }

    return false;
}

int main()
{
    int user;
    cout << "Enter the number: ";
    cin >> user;
    if (isPowerOfFour(user))
        cout << "true";
    else
        cout << "false";
}

// Example 1:

// Input: n = 6
// Output: true
// Explanation: 6 = 2 × 3
// Example 2:

// Input: n = 1
// Output: true
// Explanation: 1 has no prime factors.
// Example 3:

// Input: n = 14
// Output: false
// Explanation: 14 is not ugly since it includes the prime factor 7.
#include <iostream>
using namespace std;

bool isUgly(int num)
{
    if (num < 0)
    {
        num = -num;
    }

    for (int i = 6; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            bool isPrime = true;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int user;
    cout << "Enter the number: ";
    cin >> user;
    if (isUgly(user))
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
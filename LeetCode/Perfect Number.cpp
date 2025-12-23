#include <iostream>
using namespace std;

bool PN(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
            sum += i;
    }
    if (sum == num)
        return true;
    return false;
}
int main()
{
    int user;
    int arr[200];
    cout << "Enter the number: ";
    cin >> user;
    if (PN(user))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// Example 1:

// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
// Example 2:

// Input: num = 7
// Output: false
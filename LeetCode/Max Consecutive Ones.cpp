#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(bool nums[], int n)
{
    int max = 0;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
            check++;
        else
        {
            if (check > max)
                max = check;
            check = 0;
        }
    }
    if (check > max)
        max = check;
    return max;
}

int main()
{
    bool arr[100];
    int n;

    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << findMaxConsecutiveOnes(arr, n);
    return 0;
}

// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2
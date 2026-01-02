#include <iostream>
using namespace std;


int sumDivisibleByK(int nums[], int size, int k)
{
    int freq[201] = {0};

    for (int i = 0; i < size; i++)
        freq[nums[i]]++;

    int sum = 0;

    for (int i = 0; i < 201; i++)
    {
        if (freq[i] % k == 0 && freq[i] > 0)
            sum += i * freq[i];
    }

    return sum;
}

int main()
{
    int arr[100];
    int user;
    cout << "Enter total elements: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << sumDivisibleByK(arr, user, target);
    return 0;
}

// Example 1:
// Input: nums = [1,2,2,3,3,3,3,4], k = 2
// Output: 16
// Explanation:
// The number 1 appears once (odd frequency).
// The number 2 appears twice (even frequency).
// The number 3 appears four times (even frequency).
// The number 4 appears once (odd frequency).
// So, the total sum is 2 + 2 + 3 + 3 + 3 + 3 = 16.

// Example 2:
// Input: nums = [1,2,3,4,5], k = 2
// Output: 0
// Explanation:
// There are no elements that appear an even number of times, so the total sum is 0.

// Example 3:
// Input: nums = [4,4,4,1,2,3], k = 3
// Output: 12
// Explanation:
// The number 1 appears once.
// The number 2 appears once.
// The number 3 appears once.
// The number 4 appears three times.
// So, the total sum is 4 + 4 + 4 = 12.
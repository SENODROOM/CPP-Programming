#include <iostream>
using namespace std;
int check(int arr1[], int size1)
{
    int longest = 0;
    for (int i = 0; i < size1; i++)
    {
        int count = 0;
        for (int j = 0; j < size1; j++)
        {
            if (arr1[i] - arr1[j] == 1)
                count++;
            if (arr1[j] - arr1[i] == 1)
                count++;
        }
        if (longest < count)
            longest = count;
    }
    return longest;
}
int main()
{
    int arr[200], n;
    cout << "Enter total elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << check(arr, n);
    return 0;
}

// Example 1:

// Input: nums = [1,3,2,2,5,2,3,7]

// Output: 5

// Explanation:

// The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:

// Input: nums = [1,2,3,4]

// Output: 2

// Explanation:

// The longest harmonious subsequences are [1,2], [2,3], and [3,4], all of which have a length of 2.

// Example 3:

// Input: nums = [1,1,1,1]

// Output: 0

// Explanation:

// No harmonic subsequence exists.
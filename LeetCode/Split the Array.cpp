#include <iostream>
using namespace std;

int isPossibleToSplit(int arr[], int size)
{
    int freq[201] = {0};

    for (int i = 0; i < size; i++)
    {
        freq[arr[i]]++;
        if (freq[arr[i]] > 2)
            return false;
    }
    return true;
}

int main()
{
    int arr[100];
    int user;

    cout << "Enter total elements: ";
    cin >> user;
    while (user % 2 != 0)
    {
        cout << "Invalid elements Enter again: ";
        cin >> user;
    }

    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    isPossibleToSplit(arr, user) ? cout << "true" : cout << "false";
    return 0;
}

// Example 1:

// Input: nums = [1,1,2,2,3,4]
// Output: true
// Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and nums2 = [1,2,4].
// Example 2:

// Input: nums = [1,1,1,1]
// Output: false
// Explanation: The only possible way to split nums is nums1 = [1,1] and nums2 = [1,1]. Both nums1 and nums2 do not contain distinct elements. Therefore, we return false.
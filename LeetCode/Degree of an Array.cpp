#include <iostream>
using namespace std;

int find(int arr[], int size)
{
    int deg = 0;
    int length = size; 

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
            if (arr[i] == arr[j])
                count++;

        if (deg < count)
            deg = count;
    }

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
            if (arr[i] == arr[j])
                count++;

        if (count == deg)
        {
            int first = -1, last = -1;
            for (int k = 0; k < size; k++)
            {
                if (arr[k] == arr[i])
                {
                    if (first == -1)
                        first = k;
                    last = k;
                }
            }

            int tempLength = last - first + 1;
            if (tempLength < length)
                length = tempLength;
        }
    }

    return length;
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
    cout << find(arr, user);

    return 0;
}


// Example 1:

// Input: nums = [1,2,2,3,1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.
// Example 2:

// Input: nums = [1,2,2,3,1,4,2]
// Output: 6
// Explanation: 
// The degree is 3 because the element 2 is repeated 3 times.
// So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.
#include <iostream>
using namespace std;

int check(int arr1[], int size1)
{
    int count = 0;
    int arr2[200];

    for (int i = 0; i < size1; i++)
        arr2[i] = arr1[i];

    for (int i = 0; i < size1 - 1; i++)
    {
        for (int j = 0; j < size1 - i - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            count++;
    }

    return count;
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
    if (check(arr, n))
        cout << "true";
    else
        cout << "false";
    return 0;
}

// Example 1:

// Input: heights = [1,1,4,2,1,3]
// Output: 3
// Explanation:
// heights:  [1,1,4,2,1,3]
// expected: [1,1,1,2,3,4]
// Indices 2, 4, and 5 do not match.
// Example 2:

// Input: heights = [5,1,2,3,4]
// Output: 5
// Explanation:
// heights:  [5,1,2,3,4]
// expected: [1,2,3,4,5]
// All indices do not match.
// Example 3:

// Input: heights = [1,2,3,4,5]
// Output: 0
// Explanation:
// heights:  [1,2,3,4,5]
// expected: [1,2,3,4,5]
// All indices match.
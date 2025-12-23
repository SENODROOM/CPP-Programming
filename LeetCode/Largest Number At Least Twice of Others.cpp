#include <iostream>
using namespace std;
int LLLNum(int arr[], int n)
{
    int largest = arr[0], j;
    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
            j = i;
        }
    }
    for (int i = 0; i < n; i++)
        if (i != j && largest < arr[i] * 2)
            return -1;
    return j;
}

int main()
{
    int arr[100];
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << LLLNum(arr, n);

    return 0;
}

// Example 1:

// Input: nums = [3,6,1,0]
// Output: 1
// Explanation: 6 is the largest integer.
// For every other number in the array x, 6 is at least twice as big as x.
// The index of value 6 is 1, so we return 1.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: -1
// Explanation: 4 is less than twice the value of 3, so we return -1.
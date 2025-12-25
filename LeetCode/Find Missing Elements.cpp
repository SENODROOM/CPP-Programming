#include <iostream>
#include <algorithm>
using namespace std;

void FME(int arr[], int size)
{
    sort(arr, arr + size);

    int minVal = arr[0];
    int maxVal = arr[size - 1];

    cout << "[";
    int j = 0;

    for (int i = minVal; i <= maxVal; i++)
    {
        if (j < size && arr[j] == i)
            j++;            // number exists
        else
            cout << i << " ";  // number missing
    }
    cout << "]";
}

int main()
{
    int arr[100], n;

    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    FME(arr, n);
    return 0;
}


// Example 1:

// Input: nums = [1,4,2,5]

// Output: [3]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.

// Example 2:

// Input: nums = [7,8,6,9]

// Output: []

// Explanation:

// The smallest integer is 6 and the largest is 9, so the full range is [6,7,8,9]. All integers are already present, so no integer is missing.

// Example 3:

// Input: nums = [5,1]

// Output: [2,3,4]

// Explanation:

// The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. The missing integers are 2, 3, and 4.
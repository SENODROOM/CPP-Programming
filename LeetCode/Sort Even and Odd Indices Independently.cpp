#include <iostream>
using namespace std;

void SortEvenAndOddIndices(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int selectedIndex = i;
        if (i % 2 == 0)
        {
            for (int j = i + 2; j < size; j += 2)
            {
                if (arr[j] < arr[selectedIndex])
                    selectedIndex = j;
            }
        }
        else
        {
            for (int j = i + 2; j < size; j += 2)
            {
                if (arr[j] > arr[selectedIndex])
                    selectedIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[selectedIndex];
        arr[selectedIndex] = temp;
    }

    // Print array
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i != size - 1)
            cout << ",";
    }
    cout << "]";
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

    SortEvenAndOddIndices(arr, n);

    return 0;
}


// Example 1:

// Input: nums = [4,1,2,3]
// Output: [2,3,4,1]
// Explanation:
// First, we sort the values present at odd indices (1 and 3) in non-increasing order.
// So, nums changes from [4,1,2,3] to [4,3,2,1].
// Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
// So, nums changes from [4,1,2,3] to [2,3,4,1].
// Thus, the array formed after rearranging the values is [2,3,4,1].
// Example 2:

// Input: nums = [2,1]
// Output: [2,1]
// Explanation:
// Since there is exactly one odd index and one even index, no rearrangement of values takes place.
// The resultant array formed is [2,1], which is the same as the initial array.
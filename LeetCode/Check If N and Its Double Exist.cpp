#include <iostream>
using namespace std;
bool check(int arr1[], int size1)
{
    for (int i = 0; i < size1; i++)
        for (int j = 0; j < size1; j++)
            if (arr1[i] == (2 * arr1[j]))
                return true;
    return false;
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
        cout << "True";
    else
        cout << "False";
    return 0;
}

// Example 1:

// Input: arr = [10,2,5,3]
// Output: true
// Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:

// Input: arr = [3,1,7,11]
// Output: false
// Explanation: There is no i and j that satisfy the conditions.
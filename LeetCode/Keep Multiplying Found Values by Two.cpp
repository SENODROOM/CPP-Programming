#include <iostream>
using namespace std;

int KMFVT(int num[], int size, int original)
{
    for (int i = 0; i < size; i++)
    {
        if (num[i] == original)
        {
            original *= 2;
            i=-1;
        }
    }
    return original;
}
int main()
{
    int arr[100];
    int n,target;

    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Enter the number: ";
    cin >> target;
    cout << KMFVT(arr, n, target);

    return 0;
}

// Example 1:

// Input: nums = [5,3,6,1,12], original = 3
// Output: 24
// Explanation: 
// - 3 is found in nums. 3 is multiplied by 2 to obtain 6.
// - 6 is found in nums. 6 is multiplied by 2 to obtain 12.
// - 12 is found in nums. 12 is multiplied by 2 to obtain 24.
// - 24 is not found in nums. Thus, 24 is returned.
// Example 2:

// Input: nums = [2,7,9], original = 4
// Output: 4
// Explanation:
// - 4 is not found in nums. Thus, 4 is returned.
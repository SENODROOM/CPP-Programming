#include <iostream>
using namespace std;
int check(int arr1[], int size1)
{
    for (int i = 0; i < size1; i++)
    {
        int leftSum = 0, rightSum = 0;
        for (int j = i - 1; j >= 0; j--)
            leftSum += arr1[j];
        for (int j = i + 1; j < size1; j++)
            rightSum += arr1[j];
        if (leftSum == rightSum)
            return i;
    }
    return -1;
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

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0
#include <iostream>
using namespace std;

int CountPartitions(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        int leftsum = 0;
        for (int j = i; j > -1; j--)
            leftsum += arr[j];
        int rightSum = 0;
        for (int j = i + 1; j < size; j++)
            rightSum += arr[j];

        int temp;
        if ((leftsum - rightSum) < 0)
            temp = (rightSum - leftsum);
        else
            temp = (leftsum - rightSum);

        if (temp % 2 == 0)
            count++;
    }

    return count;
}

int main()
{
    int arr[100], arr2[100];
    int user, user2;

    cout << "Enter total elements of first array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }
    cout << CountPartitions(arr, user);

    return 0;
}


// Example 1:

// Input: nums = [10,10,3,7,6]

// Output: 4

// Explanation:

// The 4 partitions are:

// [10], [10, 3, 7, 6] with a sum difference of 10 - 26 = -16, which is even.
// [10, 10], [3, 7, 6] with a sum difference of 20 - 16 = 4, which is even.
// [10, 10, 3], [7, 6] with a sum difference of 23 - 13 = 10, which is even.
// [10, 10, 3, 7], [6] with a sum difference of 30 - 6 = 24, which is even.
// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// No partition results in an even sum difference.

// Example 3:

// Input: nums = [2,4,6,8]

// Output: 3

// Explanation:

// All partitions result in an even sum difference.

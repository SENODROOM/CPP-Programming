#include <iostream>
using namespace std;

float check(int arr[], int n)
{
    bool used[200] = {false};
    float minAvg = 1e9;

    for (int count = 0; count < n / 2; count++)
    {
        int smallest = 1e9, largest = -1e9;
        int si = -1, li = -1;

        for (int i = 0; i < n; i++)
        {
            if (!used[i])
            {
                if (arr[i] < smallest)
                {
                    smallest = arr[i];
                    si = i;
                }
                if (arr[i] > largest)
                {
                    largest = arr[i];
                    li = i;
                }
            }
        }

        used[si] = true;
        used[li] = true;

        float avg = (smallest + largest) / 2.0;
        if (avg < minAvg)
            minAvg = avg;
    }

    return minAvg;
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
// Input: nums = [7,8,3,4,15,13,4,1]
// Output: 5.5
// Explanation:
// step	nums	averages
// 0	[7,8,3,4,15,13,4,1]	[]
// 1	[7,8,3,4,13,4]	[8]
// 2	[7,8,4,4]	[8,8]
// 3	[7,4]	[8,8,6]
// 4	[]	[8,8,6,5.5]
// The smallest element of averages, 5.5, is returned.
// Example 2:
// Input: nums = [1,9,8,3,10,5]
// Output: 5.5
// Explanation:
// step	nums	averages
// 0	[1,9,8,3,10,5]	[]
// 1	[9,8,3,5]	[5.5]
// 2	[8,5]	[5.5,6]
// 3	[]	[5.5,6,6.5]
// Example 3:
// Input: nums = [1,2,3,7,8,9]
// Output: 5.0
// Explanation:
// step	nums	averages
// 0	[1,2,3,7,8,9]	[]
// 1	[2,3,7,8]	[5]
// 2	[3,7]	[5,5]
// 3	[]	[5,5,5]
// Constraints:
// 2 <= n == nums.length <= 50
// n is even.
// 1 <= nums[i] <= 50
#include <iostream>
using namespace std;

int distinctAverages(int nums[], int size)
{
    float averages[200];
    int davg = 0;
    int sexynumber = 0;
    for (int i = 0; i < size; i++)
        if (sexynumber < nums[i])
            sexynumber = nums[i];
    sexynumber++;

    while (size > 0)
    {
        int small = 2147483648, large = -2147483647, si = 0, li = 0;
        for (int i = 0; i < size; i++)
        {
            if (nums[i] != sexynumber)
            {
                if (small > nums[i])
                {
                    small = nums[i];
                    si = i;
                }
                if (large < nums[i])
                {
                    large = nums[i];
                    li = i;
                }
            }
        }
        float avg = (small + large) / 2.0;
        nums[si] = sexynumber;
        nums[li] = sexynumber;
        bool check = true;
        for (int i = 0; i < davg; i++)
        {
            if (avg == averages[i])
                check = false;
        }
        if (check)
        {
            averages[davg] = avg;
            davg++;
        }
        size -= 2;
    }
    return davg;
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

    cout << distinctAverages(arr, n);
    return 0;
}

// Example 1:

// Input: nums = [4,1,4,0,3,5]
// Output: 2
// Explanation:
// 1. Remove 0 and 5, and the average is (0 + 5) / 2 = 2.5. Now, nums = [4,1,4,3].
// 2. Remove 1 and 4. The average is (1 + 4) / 2 = 2.5, and nums = [4,3].
// 3. Remove 3 and 4, and the average is (3 + 4) / 2 = 3.5.
// Since there are 2 distinct numbers among 2.5, 2.5, and 3.5, we return 2.
// [10,2,2,0,4,0]
// Example 2:
// Input: nums = [1,100]
// Output: 1
// Explanation:
// There is only one average to be calculated after removing 1 and 100, so we return 1.
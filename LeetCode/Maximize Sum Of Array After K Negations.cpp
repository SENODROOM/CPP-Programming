#include <iostream>
using namespace std;

// Function to maximize sum after given negations
int MAXSUM(int arr[], int n, int negations)
{
    // Step 1: While we still have negations
    while (negations > 0)
    {
        // Find index of minimum element
        int minIndex = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;
        }

        // Negate only ONE element
        arr[minIndex] = -arr[minIndex];

        // One negation used
        negations--;
    }

    // Step 2: Calculate sum
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return sum;
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

    int negation;
    cout << "Total Negations: ";
    cin >> negation;

    int result = MAXSUM(arr, n, negation);

    cout << "Maximum Sum After Negations: " << result << endl;

    return 0;
}


// Example 1:

// Input: nums = [4,2,3], k = 1
// Output: 5
// Explanation: Choose index 1 and nums becomes [4,-2,3].
// Example 2:

// Input: nums = [3,-1,0,2], k = 3
// Output: 6
// Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
// Example 3:

// Input: nums = [2,-3,-1,5,-4], k = 2
// Output: 13
// Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
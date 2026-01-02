#include <iostream>
using namespace std;

/*
    LeetCode 961
    N-Repeated Element in Size 2N Array

    --------------------------------------------------
    PROBLEM STATEMENT:
    --------------------------------------------------
    You are given an integer array nums with length 2N.

    There is exactly ONE element that appears N times,
    while all other elements appear only once.

    Your task is to find and return the element that
    is repeated N times.

    --------------------------------------------------
    IMPORTANT GUARANTEE:
    --------------------------------------------------
    - Exactly one element appears N times
    - Remaining elements appear exactly once
    - Solution is guaranteed to exist
*/

/*
    --------------------------------------------------
    LOGIC EXPLANATION:
    --------------------------------------------------
    Since the repeated element appears N times (half
    the array size), it must appear close to itself.

    This means:
    - nums[i] == nums[i+1]  OR
    - nums[i] == nums[i+2]  OR
    - nums[i] == nums[i+3]

    Why?
    Because spacing all N duplicates farther apart
    than 3 is mathematically impossible in size 2N.

    Hence, checking only nearby indices guarantees
    detection.
*/

/*
    --------------------------------------------------
    FUNCTION: findRepeatedElement
    --------------------------------------------------
    INPUT:
        nums[] -> integer array
        size   -> size of array (2N)

    OUTPUT:
        Integer repeated N times
*/
int findRepeatedElement(int nums[], int size)
{
    // Loop through the array
    for (int i = 0; i < size; i++)
    {
        // Check i+1 safely
        if (i + 1 < size && nums[i] == nums[i + 1])
        {
            return nums[i];
        }

        // Check i+2 safely
        if (i + 2 < size && nums[i] == nums[i + 2])
        {
            return nums[i];
        }

        // Check i+3 safely
        if (i + 3 < size && nums[i] == nums[i + 3])
        {
            return nums[i];
        }
    }

    // This line will never execute due to problem guarantee
    return -1;
}

/*
    --------------------------------------------------
    MAIN FUNCTION (Driver Code)
    --------------------------------------------------
*/
int main()
{
    // Example input
    int nums[] = {5, 1, 5, 2, 5, 3, 5, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    // Function call
    int result = findRepeatedElement(nums, size);

    // Output the result
    cout << "The element repeated N times is: " << result << endl;

    return 0;
}

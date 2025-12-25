#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int n)
{
    // Edge cases: empty array or array with 1 or 2 elements
    if (n == 0)
        return 0;
    if (n <= 2)
        return n;

    // 'index' keeps track of the position where the next valid element should go
    int index = 2; // First two elements can always stay

    for (int i = 2; i < n; i++)
    {
        // If current element is not equal to the element two positions before,
        // it is allowed to stay (since we allow at most 2 duplicates)
        if (nums[i] != nums[index - 2])
        {
            nums[index] = nums[i];
            index++; // Move index forward for next valid element
        }
    }
    return index;
}

int main()
{
    // Example 1
    int nums1[] = {1, 1, 1, 2, 2, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int newLength1 = removeDuplicates(nums1, size1);

    cout << "New Length: " << newLength1 << endl;
    cout << "Modified Array: [";
    for (int i = 0; i < newLength1; i++)
    {
        cout << nums1[i];
        if (i < newLength1 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    // Example 2
    int nums2[] = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int newLength2 = removeDuplicates(nums2, size2);

    cout << "New Length: " << newLength2 << endl;
    cout << "Modified Array: [";
    for (int i = 0; i < newLength2; i++)
    {
        cout << nums2[i];
        if (i < newLength2 - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

/*
Explanation:

1. Since the array is sorted, duplicates are consecutive.
2. We allow at most 2 duplicates.
3. Start index at 2 because first two elements are always valid.
4. Iterate through the array starting from position 2.
5. Compare current element nums[i] with nums[index-2]:
   - If they are different, place nums[i] at nums[index] and increment index.
   - If they are same, skip the element (as it would be the 3rd duplicate).
6. Return index as the new length of the array.

Time Complexity: O(n)  -> Single pass
Space Complexity: O(1) -> In-place modification
*/

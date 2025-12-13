#include <iostream>
using namespace std;

// Array to store input numbers
int candidates[30];

// Temporary array to store the current combination while backtracking
int path[40];

// 2D array to store all valid combinations that sum to the target
int results[200][40];

// Array to store the size of each valid combination
int resultSizes[200];

// Counter for the total number of valid combinations found
int resultCount = 0;

// Number of input elements and the target sum
int n, target;

// Recursive backtracking function to find all combinations that sum to the target
// The function explores all possibilities by including or excluding each number.
//
// Parameters:
// index: current position in the candidates array
// sum: current sum of the numbers included so far
// pathSize: number of elements currently in the path array
//
// The function works as follows:
// 1. Base case 1: If the current sum equals the target, we found a valid combination.
//    - Copy the elements from 'path' into 'results'
//    - Store the size of this combination in 'resultSizes'
//    - Increment 'resultCount'
//    - Return to explore other possibilities
// 2. Base case 2: If the current index exceeds the array size or sum exceeds the target,
//    - Stop exploring this path and return.
// 3. Decision 1: Include candidates[index]
//    - Add candidates[index] to 'path'
//    - Recursive call with the same index (allows using the element again) and updated sum and pathSize
// 4. Decision 2: Exclude candidates[index]
//    - Recursive call with index + 1 (move to next element) without changing sum or pathSize
//
// Example:
// candidates = [2,3], target = 5
// Exploration:
// 1. Start with index=0, sum=0, path=[]
//    - Include 2 -> path=[2], sum=2
//        - Include 2 again -> path=[2,2], sum=4
//            - Include 2 again -> sum=6 (exceeds target, return)
//            - Exclude 2, move to index=1 -> path=[2,2], sum=4
//                - Include 3 -> sum=7 (exceeds target, return)
//                - Exclude 3 -> index out of bounds, return
//        - Exclude 2, move to index=1 -> path=[2], sum=2
//            - Include 3 -> sum=5 ✅ store combination [2,3]
//            - Exclude 3 -> index out of bounds, return
//    - Exclude 2, move to index=1 -> path=[], sum=0
//        - Include 3 -> path=[3], sum=3
//            - Include 3 again -> sum=6 (exceeds target, return)
//            - Exclude 3 -> index out of bounds, return
//        - Exclude 3 -> index out of bounds, return
// Result: [ [2,3] ]
void backtrack(int index = 0, int sum = 0, int pathSize = 0)
{
    // Base case 1: If current sum equals the target
    if (sum == target)
    {
        // Copy the current path to results
        for (int i = 0; i < pathSize; i++)
            results[resultCount][i] = path[i];
        
        // Store the size of this combination
        resultSizes[resultCount] = pathSize;
        
        // Increment the total valid combinations counter
        resultCount++;
        return; // Return to explore other paths
    }

    // Base case 2: If index exceeds array bounds or sum exceeds target
    if (index == n || sum > target)
        return; // Stop exploring this path

    // --- Decision 1: Include candidates[index] ---
    path[pathSize] = candidates[index]; // Add to path
    // Recursive call: include same element again (unlimited usage allowed)
    backtrack(index, sum + candidates[index], pathSize + 1);

    // --- Decision 2: Exclude candidates[index] ---
    // Move to next element without changing sum or path
    backtrack(index + 1, sum, pathSize);
}

int main()
{
    cout << "Size of array: ";
    cin >> n; // Input number of elements

    // Input the array elements from the user
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> candidates[i];
    }

    cout << "Enter the target: ";
    cin >> target; // Input the target sum

    // Sort the array in ascending order using bubble sort
    // Sorting ensures combinations are in increasing order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (candidates[j] > candidates[j + 1])
            {
                int t = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = t;
            }
        }
    }

    // Start backtracking from index 0, sum 0, and empty path
    backtrack();

    // Print all the valid combinations found
    cout << "[";
    for (int i = 0; i < resultCount; i++)
    {
        cout << "[";
        for (int j = 0; j < resultSizes[i]; j++)
        {
            cout << results[i][j];
            if (j + 1 < resultSizes[i])
                cout << ","; // Separate numbers with commas
        }
        cout << "]";
        if (i + 1 < resultCount)
            cout << ","; // Separate combinations with commas
    }
    cout << "]";

    return 0;
}

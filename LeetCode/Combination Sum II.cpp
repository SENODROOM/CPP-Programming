#include <iostream>
using namespace std;

const int MAX = 100;

// Array to store the input numbers
int candidates[MAX];

// Temporary array to store the current combination during backtracking
int path[MAX];

// 2D array to store all valid combinations
int results[1000][MAX];

// Array to store the size of each combination
int resultSizes[1000];

// Counter to keep track of the number of valid combinations found
int resultCount = 0;

// Number of candidates and the target sum
int n, target;

/*
 * Simple bubble sort to sort the candidates in ascending order
 * Sorting helps to handle duplicates and also allows early termination
 * when the current sum exceeds the target.
 */
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
 * Recursive backtracking function to find all unique combinations
 * that sum to the target.
 *
 * Parameters:
 * index: current starting index in the candidates array
 * sum: sum of the current combination stored in 'path'
 * pathSize: number of elements currently in the 'path' array
 *
 * Key points:
 * 1. Each element can be used **only once** in a combination.
 * 2. Skips duplicates by checking if the current element is same as the previous.
 * 3. Stops exploring a path if the sum exceeds the target.
 *
 * Example:
 * candidates = [1,1,2,5], target = 3
 * Sorted candidates = [1,1,2,5]
 * Exploration:
 * - Start with index=0, sum=0, path=[]
 *   - Include 1 -> path=[1], sum=1
 *       - Move to index=1
 *           - Skip 1 (duplicate)
 *           - Include 2 -> path=[1,2], sum=3 ✅ store combination
 *       - Move to index=2
 *           - Include 2 -> path=[1,2] (already stored)
 *           - Include 5 -> sum>target, return
 *   - Move to index=1
 *       - Skip 1 (duplicate)
 *   - Move to index=2
 *       - Include 2 -> path=[2], sum=2
 *           - Move to index=3
 *               - Include 5 -> sum>target, return
 * Result: [ [1,2], [2,1] ] (order may vary, duplicates removed)
 */
void backtrack(int index, int sum, int pathSize)
{
    // Base case: if current sum equals the target
    if (sum == target)
    {
        // Store the combination in results
        for (int i = 0; i < pathSize; i++)
            results[resultCount][i] = path[i];

        // Store the size of this combination
        resultSizes[resultCount] = pathSize;

        // Increment the valid combination counter
        resultCount++;
        return; // Return to explore other combinations
    }

    // Iterate over candidates starting from 'index'
    for (int i = index; i < n; i++)
    {
        // Skip duplicates: if current element is same as previous at same depth
        if (i > index && candidates[i] == candidates[i - 1])
            continue;

        // If sum exceeds target, skip this element
        if (sum + candidates[i] > target)
            continue;

        // Include candidates[i] in the current path
        path[pathSize] = candidates[i];

        // Recursive call: move to the next index because each element can be used once
        backtrack(i + 1, sum + candidates[i], pathSize + 1);
    }
}

int main()
{
    // Input number of candidates
    cout << "Enter number of candidates: ";
    cin >> n;

    // Input the candidate numbers
    for (int i = 0; i < n; i++)
    {
        cout << "Enter candidates: ";
        cin >> candidates[i];
    }

    // Input target sum
    cout << "Enter target: ";
    cin >> target;

    // Sort the candidates to simplify handling duplicates and enable early stopping
    bubbleSort(candidates, n);

    // Start backtracking from index 0, sum 0, and empty path
    backtrack(0, 0, 0);

    // Print all valid combinations found
    cout << "Combinations are:\n";
    for (int i = 0; i < resultCount; i++)
    {
        cout << "[";
        for (int j = 0; j < resultSizes[i]; j++)
        {
            cout << results[i][j];
            if (j != resultSizes[i] - 1)
                cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}

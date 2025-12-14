#include <iostream>
using namespace std;

/*
=====================================================================
                       JUMP GAME II
=====================================================================

Problem Statement:
------------------
You are given an array `arr[]` of length `n`, where each element 
represents the **maximum number of steps you can jump forward** from 
that position. The goal is to find the **minimum number of jumps** 
needed to reach the last index of the array starting from the first 
element.

Example:
--------
Input:  arr = [2,3,1,1,4]
Output: 2
Explanation:
- Start at index 0 (value 2). We can jump 1 step to index 1 or 2 steps to index 2.
- The optimal path is:
    Jump 1 step to index 1 (value 3)
    Then jump 3 steps to index 4 (end of array)
- Total jumps = 2

Another Example:
----------------
Input: arr = [1,1,1,1,1]
Output: 4
Explanation:
- Here each element allows only 1 step.
- So we need 4 jumps to move from index 0 to 4.

=====================================================================
*/

int minJumps(int arr[], int n, int start) {
    /*
    Function: minJumps
    -----------------
    This function recursively computes the **minimum number of jumps** 
    needed to reach the end of the array from the current position `start`.

    Parameters:
    - arr[]: The array of integers representing max jumps at each position.
    - n: Size of the array.
    - start: The current position in the array from which we are calculating jumps.

    Returns:
    - Minimum number of jumps to reach or pass the last index from position `start`.
    */

    // Base Case 1:
    // If our current position is beyond or at the last index,
    // no more jumps are needed.
    if (start >= n - 1) {
        // Debug info (optional)
        // cout << "Reached end from index " << start << endl;
        return 0;
    }

    // Base Case 2:
    // If the current element is 0, we cannot move forward from here
    // So we return a large number to indicate it's impossible
    if (arr[start] == 0) {
        // 1e9 is a large number simulating infinity
        return 1e9;
    }

    // Initialize minimum jumps to a very large number
    int min_jump = 1e9;

    /*
    Recursive Case:
    ----------------
    We try all possible jumps from 1 to arr[start] (maximum jump allowed 
    from current index) and recursively calculate the number of jumps 
    needed from the new position.

    Steps:
    1. Loop from jump = 1 to arr[start]
    2. Recursively call minJumps from the new position: start + jump
    3. Add 1 because we made a jump
    4. Update min_jump if the computed jumps are smaller
    */

    for (int jump = 1; jump <= arr[start]; jump++) {
        // Recursive call to calculate jumps from the new position
        int jumps_needed = 1 + minJumps(arr, n, start + jump);

        // Update min_jump if this path gives fewer jumps
        if (jumps_needed < min_jump)
            min_jump = jumps_needed;

        /*
        Debug info (optional):
        cout << "From index " << start << " trying jump " << jump
             << " leads to " << jumps_needed << " total jumps." << endl;
        */
    }

    // Return the minimum jumps calculated from this position
    return min_jump;
}

/*
=====================================================================
                             MAIN FUNCTION
=====================================================================

Steps:
------
1. Take the size of the array as input.
2. Read all elements into the array.
3. Call minJumps starting from index 0.
4. Print the minimum number of jumps.

=====================================================================
*/

int main() {
    int n;
    cout << "Enter total elements: ";
    cin >> n; // e.g., input: 5

    // Declare array of size 100 (sufficient for most small examples)
    int arr[100];

    // Read array elements from user
    for (int i = 0; i < n; i++) {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
        /*
        Example:
        If user inputs arr = [2,3,1,1,4]
        arr[0] = 2, arr[1] = 3, arr[2] = 1, arr[3] = 1, arr[4] = 4
        */
    }

    // Call the recursive function to compute minimum jumps
    int result = minJumps(arr, n, 0);

    /*
    Print the result
    ----------------
    Note: If the result is very large (1e9), it means the end is unreachable
    */
    if (result >= 1e9)
        cout << "End of array is not reachable." << endl;
    else
        cout << "Minimum jumps needed: " << result << endl;

    return 0;
}

/*
=====================================================================
                           EXPLANATION OF ALGORITHM
=====================================================================

1. The function uses a **recursive brute-force approach**.
2. From the current index, it tries all possible jumps and recursively finds the minimum path.
3. The recursion explores **all possible paths** to the end.
4. Base Cases:
    - If we reach or cross the last index, return 0 (no jumps needed).
    - If the current index has value 0, return infinity (cannot move forward).
5. Recurrence Relation:
    - minJumps(start) = 1 + min( minJumps(start+1), minJumps(start+2), ..., minJumps(start+arr[start]) )
6. Time Complexity:
    - This approach is **exponential O(2^n)** in the worst case because it explores all jump sequences.
7. Space Complexity:
    - O(n) due to recursion stack.
8. Limitations:
    - For large arrays, this will be **very slow**.
    - Optimizations can be done using **Dynamic Programming or Greedy approaches**.

=====================================================================
                             EXAMPLES
=====================================================================

Example 1:
----------
Input: [2,3,1,1,4]
Step-by-step:
- Start at index 0 (value 2)
    - Jump 1 to index 1 (value 3) → recursively find min jumps from 1
        - From index 1 (value 3):
            - Jump 1 → index 2
            - Jump 2 → index 3
            - Jump 3 → index 4 (end)
        - Minimum jumps from index 1 = 1
    - Jump 2 to index 2 (value 1) → recursively find min jumps from 2
        - From index 2 (value 1):
            - Jump 1 → index 3
                - From index 3 (value 1) → jump 1 → index 4 (end)
        - Minimum jumps from index 2 = 2
- Compare paths: min(1+1, 1+2) = 2

Output: 2

Example 2:
----------
Input: [1,1,1,1,1]
- Must take 1 step each time
- Total jumps = 4

Example 3:
----------
Input: [0,1,2]
- Cannot move from index 0
- Output: Infinity → "End of array not reachable"

=====================================================================
*/

/*
=====================================================================
                           ADDITIONAL NOTES
=====================================================================

1. Recursive brute-force is useful for understanding the problem.
2. For better performance:
   - Use **Memoization** to store results of minJumps for each index.
   - Or use **Dynamic Programming bottom-up** approach.
   - Or use **Greedy approach** (linear time O(n)).
3. Recursive visualization:
   - The recursion forms a **tree of possible jumps**.
   - Each node = current index
   - Each edge = a jump from that index
   - Leaves = reaching end of array or dead-end
4. This code **does not use vectors**, and sticks to a plain array as requested.

=====================================================================
*/


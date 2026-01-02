#include <iostream>
using namespace std;

/*
    LeetCode 756 - Pyramid Transition Matrix
    Constraint-based DFS + Backtracking
    Using ONLY <iostream>
*/

/*
    Since we are not allowed to use STL containers,
    we will manually store allowed transitions.

    allowedPairs[i][0] = first character
    allowedPairs[i][1] = second character
    allowedPairs[i][2] = top character
*/
char allowedPairs[200][3];
int allowedCount = 0;

/*
    This function checks whether we can build the pyramid
    starting from the current row.
*/
bool canBuild(char current[], int length)
{
    /*
        Base Case:
        If length == 1, we have successfully built the pyramid
    */
    if (length == 1)
        return true;

    /*
        nextRow will store the row above the current row
        Its length is always (length - 1)
    */
    char nextRow[10];

    /*
        We now need to generate ALL possible next rows
        using backtracking.
    */

    /*
        Helper recursion inside this function:
        pos = index we are filling in nextRow
    */
    for (int mask = 0; mask < 1; mask++)
    {
    } // dummy loop to allow block scoping

    // Recursive backtracking using a manual stack approach
    int pos = 0;
    int choiceIndex[10]; // tracks which allowed rule we are using at each position
    for (int i = 0; i < 10; i++)
        choiceIndex[i] = -1;

    while (true)
    {
        if (pos == length - 1)
        {
            /*
                We have successfully built one full nextRow
                Now recursively check if pyramid can be built above it
            */
            if (canBuild(nextRow, length - 1))
                return true;

            // Backtrack
            pos--;
            if (pos < 0)
                break;
        }
        else
        {
            bool found = false;

            /*
                Try all allowed transitions
                that match current[pos] and current[pos + 1]
            */
            for (int i = choiceIndex[pos] + 1; i < allowedCount; i++)
            {
                if (allowedPairs[i][0] == current[pos] &&
                    allowedPairs[i][1] == current[pos + 1])
                {
                    // Valid transition found
                    nextRow[pos] = allowedPairs[i][2];
                    choiceIndex[pos] = i;
                    found = true;
                    pos++;
                    if (pos < 10)
                        choiceIndex[pos] = -1;
                    break;
                }
            }

            if (!found)
            {
                // No valid transition → backtrack
                choiceIndex[pos] = -1;
                pos--;
                if (pos < 0)
                    break;
            }
        }
    }

    return false;
}

/*
    Main function to solve the problem
*/
bool pyramidTransition(string bottom, string allowed[], int n)
{
    /*
        Store allowed transitions into our manual array
    */
    allowedCount = 0;
    for (int i = 0; i < n; i++)
    {
        allowedPairs[allowedCount][0] = allowed[i][0];
        allowedPairs[allowedCount][1] = allowed[i][1];
        allowedPairs[allowedCount][2] = allowed[i][2];
        allowedCount++;
    }

    /*
        Convert bottom string to char array
    */
    char base[10];
    int len = bottom.length();
    for (int i = 0; i < len; i++)
        base[i] = bottom[i];

    return canBuild(base, len);
}

/*
    Driver Code (for understanding / testing)
*/
int main()
{
    string bottom;
    cout << "Enter the target: ";
    cin >> bottom;
    int n;
    string allowed[200];
    cout << "Enter value of n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of allowed[" << i << "]: ";
        cin >> allowed[i];
    }

    if (pyramidTransition(bottom, allowed, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Example 1:

// Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
// Output: true
// Explanation: The allowed triangular patterns are shown on the right.
// Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
// There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
// Example 2:

// Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
// Output: false
// Explanation: The allowed triangular patterns are shown on the right.
// Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.

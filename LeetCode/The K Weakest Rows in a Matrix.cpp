#include <iostream>
using namespace std;

/***************************************************************
                    FUNCTION: countSoldiers
****************************************************************
PURPOSE:
--------
This function is used to calculate how many soldiers are present
in a single row of the matrix.

In the given problem:
- A value of 1 represents a SOLDIER
- A value of 0 represents a CIVILIAN

IMPORTANT PROPERTY OF EACH ROW:
-------------------------------
Each row of the matrix is already SORTED such that:
- All soldiers (1s) appear FIRST
- All civilians (0s) appear AFTER soldiers

Example Row:
------------
Row = [1, 1, 1, 0, 0]

Here:
- Soldiers = 3
- Civilians = 2

Because of this sorted structure, once we encounter the first 0,
we are guaranteed that there are NO more soldiers in that row.

---------------------------------------------------------------
FUNCTION PARAMETERS:
--------------------
row[]  -> An array representing a single row of the matrix
cols   -> Total number of columns in the row

RETURN VALUE:
-------------
Returns an integer representing the total number of soldiers (1s)
present in the row.

---------------------------------------------------------------
ALGORITHM (STEP-BY-STEP):
-------------------------
1. Start a counter with value 0
2. Traverse the row from left to right
3. If the current element is 1:
      - Increment the counter
4. If the current element is 0:
      - Stop the loop immediately using 'break'
5. Return the final count

---------------------------------------------------------------
TIME COMPLEXITY:
----------------
Worst Case: O(cols)
Best Case:  O(1)  (if first element is 0)

---------------------------------------------------------------
SPACE COMPLEXITY:
-----------------
O(1) → Uses constant extra space

***************************************************************/
int countSoldiers(int row[], int cols)
{

    // Variable to store the number of soldiers found in the row
    int count = 0;

    /*
        Loop through each column of the row
        We start from index 0 and move towards the end
    */
    for (int i = 0; i < cols; i++)
    {

        /*
            If the current cell contains 1,
            it means we have found a soldier
        */
        if (row[i] == 1)
        {

            // Increase the soldier count
            count++;
        }
        else
        {

            /*
                As soon as we encounter a 0,
                we stop counting because:
                - The row is sorted
                - No more soldiers can appear after this
            */
            break;
        }
    }

    /*
        Return the total number of soldiers found
        in the given row
    */
    return count;
}

int main()
{

    int rows, cols, k;

    /****************************************************************
                         INPUT SECTION
    *****************************************************************

    PURPOSE:
    --------
    This section of the program is responsible for taking all required
    inputs from the user. These inputs define:

    1. The size of the matrix (rows and columns)
    2. The value of k (number of weakest rows to be found)
    3. The actual values of the matrix (0s and 1s)

    ---------------------------------------------------------------
    MEANING OF INPUT VALUES:
    ------------------------
    - rows    -> Total number of rows in the matrix
    - cols    -> Total number of columns in the matrix
    - k       -> Number of weakest rows required as output

    MATRIX VALUE CONVENTION:
    -----------------------
    - 1 represents a SOLDIER
    - 0 represents a CIVILIAN

    Each row must be entered such that:
    - All 1s appear before 0s (sorted row property)

    ****************************************************************/

    // Prompt user to enter the number of rows
    cout << "Enter number of rows in the matrix: ";
    cin >> rows;

    // Prompt user to enter the number of columns
    cout << "Enter number of columns in the matrix: ";
    cin >> cols;

    // Prompt user to enter the value of k
    cout << "Enter value of k (number of weakest rows to find): ";
    cin >> k;

    /*
        Declare a 2D array to store the matrix.
        Maximum size is fixed at 100 x 100 to handle
        all possible test cases safely.
    */
    int mat[100][100];

    // Inform user about allowed input values
    cout << "\nEnter matrix values (only 0 or 1 allowed):\n";
    cout << "(Soldiers = 1, Civilians = 0)\n\n";

    /*
        Nested loop to input matrix values row by row
    */
    for (int i = 0; i < rows; i++)
    {

        /*
            Prompt user for values of the current row
        */
        cout << "Row " << i << " values:\n";

        for (int j = 0; j < cols; j++)
        {

            /*
                Prompt user for each column value
                of the current row
            */
            cout << "  Column " << j << ": ";
            cin >> mat[i][j];
        }

        // Add a blank line after each row for better readability
        cout << endl;
    }

    /*
        Arrays to store:
        soldiers count per row
        original row indices
    */
    int soldiers[100];
    int index[100];

    // ----- COUNT SOLDIERS -----
    for (int i = 0; i < rows; i++)
    {
        soldiers[i] = countSoldiers(mat[i], cols);
        index[i] = i;
    }

    // ----- SORT USING BUBBLE SORT -----
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {

            bool shouldSwap = false;

            if (soldiers[j] > soldiers[j + 1])
            {
                shouldSwap = true;
            }
            else if (soldiers[j] == soldiers[j + 1] &&
                     index[j] > index[j + 1])
            {
                shouldSwap = true;
            }

            if (shouldSwap)
            {
                int tempSoldiers = soldiers[j];
                soldiers[j] = soldiers[j + 1];
                soldiers[j + 1] = tempSoldiers;

                int tempIndex = index[j];
                index[j] = index[j + 1];
                index[j + 1] = tempIndex;
            }
        }
    }

    // ----- OUTPUT RESULT -----
    cout << "\nThe " << k << " weakest rows are:\n";

    for (int i = 0; i < k; i++)
    {
        cout << "Weak Row " << (i + 1)
             << " -> Row Index: " << index[i]
             << " (Soldiers: " << soldiers[i] << ")\n";
    }

    cout << "\nProgram finished successfully.\n";

    return 0;
}

// Example 1:

// Input: mat =
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]],
// k = 3
// Output: [2,0,3]
// Explanation:
// The number of soldiers in each row is:
// - Row 0: 2
// - Row 1: 4
// - Row 2: 1
// - Row 3: 2
// - Row 4: 5
// The rows ordered from weakest to strongest are [2,0,3,1,4].
// Example 2:

// Input: mat =
// [[1,0,0,0],
//  [1,1,1,1],
//  [1,0,0,0],
//  [1,0,0,0]],
// k = 2
// Output: [0,2]
// Explanation:
// The number of soldiers in each row is:
// - Row 0: 1
// - Row 1: 4
// - Row 2: 1
// - Row 3: 1
// The rows ordered from weakest to strongest are [0,2,3,1].
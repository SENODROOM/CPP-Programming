#include <iostream>
using namespace std;

int main()
{
    int kutti[200];
    int n;
    cout << "Enter the n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]: ";
        cin >> kutti[i];
    }

    int n1, m1;
    cout << "Enter the rows: ";
    cin >> n1;
    cout << "Enter the column: ";
    cin >> m1;


    if (n1 * m1 == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << kutti[i] << " ";
            if ((i + 1) % m1 == 0)
                cout << "\n";
        }
    }

    return 0;
}

// Example 1:
// Input: original = [1,2,3,4], m = 2, n = 2
// Output: [[1,2],[3,4]]
// Explanation: The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
// Example 2:
// Input: original = [1,2,3], m = 1, n = 3
// Output: [[1,2,3]]
// Explanation: The constructed 2D array should contain 1 row and 3 columns.
// Put all three elements in original into the first row of the constructed 2D array.
// Example 3:
// Input: original = [1,2], m = 1, n = 1
// Output: []
// Explanation: There are 2 elements in original.
// It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
#include <iostream>
using namespace std;

bool Toeplitz(int arr[][10], int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != arr[i - 1][j - 1])
                return false;
        }
    }
    return true;
}

int main()
{
    int arr[10][10];
    int n;
    cout << "Enter the n: ";
    cin >> n;
    int m;
    cout << "Enter the n: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    if (Toeplitz(arr, n, m))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}

// Example 1:
// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: true
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.
// Example 2:
// Input: matrix = [[1,2],[2,2]]
// Output: false
// Explanation:
// The diagonal "[1, 2]" has different elements.
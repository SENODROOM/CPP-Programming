#include <iostream>
using namespace std;

int SpecialPositions(int arr[][10], int n, int m)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                bool isSpecial = true;

                // Check row i
                for (int col = 0; col < m; col++)
                {
                    if (col != j && arr[i][col] == 1)
                    {
                        isSpecial = false;
                        break;
                    }
                }

                // Check column j
                if (isSpecial)
                {
                    for (int row = 0; row < n; row++)
                    {
                        if (row != i && arr[row][j] == 1)
                        {
                            isSpecial = false;
                            break;
                        }
                    }
                }

                if (isSpecial)
                    count++;
            }
        }
    }

    return count;
}

int main()
{
    int arr[10][10];
    int n, m;

    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    // Input matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "Number of special positions: " << SpecialPositions(arr, n, m) << endl;

    return 0;
}




// Example 1:


// Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// Output: 1
// Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
// Example 2:


// Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
// Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
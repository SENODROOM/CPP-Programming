#include <iostream>
using namespace std;

int SUM(int arr[][10], int n1)
{
    int result = 0;

    // Primary diagonal
    for (int k = 0; k < n1; k++)
        result += arr[k][k];

    // Secondary diagonal
    for (int k = 0; k < n1; k++)
        result += arr[k][n1 - 1 - k];

    // Remove center element if n is odd (counted twice)
    if (n1 % 2 != 0)
        result -= arr[n1 / 2][n1 / 2];

    return result;
}


int main()
{
    int arr[10][10];
    int n;
    cout << "Enter the n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << SUM(arr, n);

    return 0;
}




// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int grid[100][100];
    int maxLocal[98][98]; // n-2 max 98 because n <= 100

    // Input grid
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // Compute maxLocal
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int localMax = grid[i][j]; // start with top-left of 3x3
            // check 3x3 submatrix
            for (int x = i; x <= i + 2; x++) {
                for (int y = j; y <= j + 2; y++) {
                    if (grid[x][y] > localMax)
                        localMax = grid[x][y];
                }
            }
            maxLocal[i][j] = localMax;
        }
    }

    // Print maxLocal
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            cout << maxLocal[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}








// Example 1:
// Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
// Output: [[9,9],[8,6]]
// Explanation: The diagram above shows the original matrix and the generated matrix.
// Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
// Example 2:
// Input: grid = [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
// Output: [[2,2,2],[2,2,2],[2,2,2]]
// Explanation: Notice that the 2 is contained within every contiguous 3 x 3 matrix in grid.
 
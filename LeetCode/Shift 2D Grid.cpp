#include <iostream>
using namespace std;

void shiftGrid(int grid[50][50], int m, int n, int k)
{
    int total = m * n;
    k = k % total;

    int result[50][50];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i * n + j;
            int newIdx = (idx + k) % total;

            int r = newIdx / n;
            int c = newIdx % n;

            result[r][c] = grid[i][j];
        }
    }

    // Copy back
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = result[i][j];
}

int main()
{
    int grid[50][50] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int m = 3, n = 3, k = 1;

    shiftGrid(grid, m, n, k);

    // Print result
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    return 0;
}

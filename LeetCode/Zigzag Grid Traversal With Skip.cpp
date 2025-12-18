#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter rows (n) and cols (m): ";
    cin >> n >> m;

    int grid[50][50];

    // Input grid
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    bool skip = false; // track alternate cell skipping

    // Traverse each row
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            // Move right
            for (int j = 0; j < m; j++)
            {
                if (!skip)
                {
                    cout << grid[i][j] << " ";
                }
                skip = !skip;
            }
        }
        else
        {
            // Move left
            for (int j = m - 1; j >= 0; j--)
            {
                if (!skip)
                {
                    cout << grid[i][j] << " ";
                }
                skip = !skip;
            }
        }
    }

    cout << endl;
    return 0;
}

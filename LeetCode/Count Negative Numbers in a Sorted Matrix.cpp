#include <iostream>
using namespace std;

int countNegatives(int n, int grid[][10])
{
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] < 0)
                neg++;
        }
    }
    return neg;
}

int main()
{
    int n;
    cout << "Enter size n: ";
    cin >> n;

    int mat[10][10], target[10][10];

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << countNegatives(n, mat);

    return 0;
}

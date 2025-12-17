#include <iostream>
using namespace std;

void Reshape(int arr[][10], int n1, int m1, int n2, int m2)
{
    if (n1 * m1 != n2 * m2)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m1; j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
        return;
    }

    int r = 0, c = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < m1; j++)
        {
            cout << arr[i][j] << " ";
            c++;

            if (c == m2)
            {
                cout << "\n";
                c = 0;
            }
        }
    }
}

int main()
{
    int arr[10][10];
    int n;
    cout << "Enter the n: ";
    cin >> n;
    int m;
    cout << "Enter the m: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    int n1;
    cout << "Enter the n: ";
    cin >> n1;
    int m1;
    cout << "Enter the m: ";
    cin >> m1;
    Reshape(arr, n, m, n1, m1);

    return 0;
}

// Example 1:
// Input: mat = [[1,2],[3,4]], r = 1, c = 4
// Output: [[1,2,3,4]]
// Example 2:

// Input: mat = [[1,2],[3,4]], r = 2, c = 4
// Output: [[1,2],[3,4]]
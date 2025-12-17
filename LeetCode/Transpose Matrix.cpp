#include <iostream>
using namespace std;

void Transpose(int arr[][10], int n1, int m1)
{
    for (int j = 0; j < m1; j++) 
    {
        for (int i = 0; i < n1; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
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
    Transpose(arr, n, m);

    return 0;
}


// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:

// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]
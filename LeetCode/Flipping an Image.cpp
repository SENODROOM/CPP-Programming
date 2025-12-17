#include <iostream>
using namespace std;

void Flipping(bool arr[][10], int n1, int m1)
{
    for (int i = 0; i < n1; i++) 
    {
        for (int j = m1-1; j >-1; j--)
        {
            cout << !(arr[i][j]) << " ";
        }
        cout << "\n";
    }
}


int main()
{
    bool arr[10][10];
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
    Flipping(arr, n, m);

    return 0;
}


// Example 1:

// Input: image = [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
// Example 2:

// Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
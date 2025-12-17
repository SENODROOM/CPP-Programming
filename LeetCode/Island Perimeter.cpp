#include <iostream>
using namespace std;

int Island(bool arr[][10], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                if (arr[i - 1][j] == 0 ||!(arr[i - 1][j]))
                    count++;
                if (arr[i][j - 1] == 0||!(arr[i][j - 1]))
                    count++;
                if (arr[i + 1][j] == 0||!(arr[i +1][j]))
                    count++;
                if (arr[i][j + 1] == 0||!(arr[i][j+1]))
                    count++;
            }
        }
    }

    return count;
}

int main()
{
    bool arr[10][10];
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
    cout << Island(arr, n);

    return 0;
}


// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.
// Example 2:

// Input: grid = [[1]]
// Output: 4
// Example 3:

// Input: grid = [[1,0]]
// Output: 4
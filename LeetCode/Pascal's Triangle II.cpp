#include <iostream>
using namespace std;
int main()
{
    int row;
    int arr[100][100];

    cout << "Enter no of rows: ";
    cin >> row;

    for (int i = 0; i < row + 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
    // for (int i = 0; i < row + 1; i++)
    // {

    //     for (int s = 0; s < row + 1 - i - 1; s++)
    //         cout << " ";

    //     for (int j = 0; j <= i; j++)
    //         cout << arr[i][j] << " ";

    //     cout << endl;
    // }
    for (int j = 0; j <= row; j++)
        cout << arr[row][j] << " ";
}
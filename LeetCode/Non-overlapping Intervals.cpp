#include <iostream>
using namespace std;
int main()
{
    int col = 2, row, arr[100][100];
    cout << "Enter no  of total array: ";
    cin >> row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter " << j + 1 << " element of " << i + 1 << " array:  ";
            cin >> arr[i][j];
        }
    }
    int subtract = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            for (int m = i + 1; m < row; m++)
            {
                if (arr[i][j] == arr[m][j])
                {
                    for (int k = m; k < row; k++)
                    {
                        arr[k][j] = arr[k + 1][j];
                    }
                    for (int l = j; l < col; l++)
                    {
                        arr[m][j] = arr[m][j + 1];
                    }
                    subtract++;
                    row--;
                }
            }
        }
    }
    cout << subtract;
}
#include <iostream>
using namespace std;
int main()
{
    int arr[100][100];
    int col = 2, row;
    cout << "Enter no of total array:  ";
    cin >> row;
    for (int i = 0; i < row; i++)
    {
        cout << "Enter starting and ending points  of array  " << i + 1 << " : ";
        cout << endl;
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
            if (j == 1)
            {
                if (arr[i][j - 1] == arr[i][j] || arr[i][j - 1] > arr[i][j])
                {
                    do
                    {
                        cout << "Start and end point can not be same and start point should be smaller . Enter again: ";
                        cin >> arr[i][j];

                    } while (arr[i][j - 1] == arr[i][j] || arr[i][j - 1] > arr[i][j]);
                }
            }
        }
    }
    int array[100];

    for (int i = 0; i < row; i++)

    {
        int j = 1;
        int end = arr[i][1];
        for (int m = 0; m < row; m++)
        {
            int start = arr[m][j - 1];
            if (start == end)
            {
                array[i] = m;

                break;
            }
            else
            {
                array[i] = -1;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        cout << array[i] << " ";
    }
}
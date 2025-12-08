#include <iostream>
using namespace std;
void sorted(int num[][100], int sort[], int row, int colrow[])
{
    int l = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colrow[i]; j++)
        {
            sort[l] = num[i][j];
            l++;
        }
    }
    for (int k = 0; k < l; k++)
    {
        for (int m = k; m < l; m++)
        {
            if (sort[m] < sort[k])
            {
                int temp;
                temp = sort[k];
                sort[k] = sort[m];
                sort[m] = temp;
            }
        }
    }
    cout << "[";
    for (int k = 0; k < l; k++)
    {
        cout << sort[k];
        if (k<l-1)
        {   
            cout << ",";
        }
    }
    cout << "]";
}

int main()
{
    int num[100][100];
    int row;
    int sort[100];
    int colrow[100];

    cout << "Enter total array: ";
    cin >> row;
    for (int i = 0; i < row; i++)
    {
        cout << "Enter number of elements in array " << i + 1 << " :";
        cin >> colrow[i];
        for (int j = 0; j < colrow[i]; j++)
        {
            cout << "Enter element " << j + 1 << " :";
            cin >> num[i][j];
        }
    }
    sorted(num, sort, row, colrow);
}
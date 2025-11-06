#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int arr[3][3] = {{2, 3, 4}, {14, 5, 6}, {6, 17, 8}};
    int trans[3][3];
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << setw(3) << left << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trans[j][i] = arr[i][j];
        }
    }
    cout << "*******Transposed*******" << endl;
    for (int i = 0, j = 0; i < 3;)
    {

        if (j < 3)
        {
            cout << trans[i][j] << " ";
            j++;
        }
        else
        {
            j = 0;
            i++;
            cout << endl;
        }
    }
}
#include <iostream>
using namespace std;
int main()
{
    int arr2[2][2] = { {12,13},{14,15} };
    int arr3[2][2];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arr3[j][i] = arr2[i][j];
        }

    }
    cout << "*********transposed***********" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr3[i][j] << " ";

        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int main()
{
    int arr[3][2] = {};
    int sum = 0;
    cout << sizeof(arr[0]) << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Input value for arr[" << i << "][" << j << "]"<<endl;
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 2; j++)
        {
            sum+=arr[i][j];
        }
        cout << (float)sum / 2 << endl;
        cout << endl;
    }
}
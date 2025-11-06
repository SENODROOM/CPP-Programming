#include <iostream>
using namespace std;
int main()
{
    system("CLS");
    int arr[5][5] = { {2,3,4,5,6},{4,5,4,5,6},{1,1,1,1,1},{3,4,5,6,6},{4,6,7,7,6}};
    int rows = 5, cols = 5;
    int mid = rows / 2;
    for (int i = 0; i < cols; i++)
    {
        cout << arr[mid][i]<<" ";
    }
}
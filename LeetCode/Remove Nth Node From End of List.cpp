#include <iostream>
using namespace std;
int main()
{
    int user;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr[" << i << "]" << ": ";
        cin >> arr[i];
    }
    int n;
    cout << "Enter the n: ";
    cin>>n;
    int narr[200];
    int m = user - n;
    int k = 0;
    for (int i = 0; i < user; i++)
    {
        if (i != m)
        {
            narr[k] = arr[i];
            k++;
        }
    }
    cout << "[";
    for (int i = 0; i < k; i++)
    {
        if (i == k - 1)
        {
            cout << narr[i];
        }
        else
        {
            cout << narr[i] << ",";
        }
    }
    cout << "]";
}
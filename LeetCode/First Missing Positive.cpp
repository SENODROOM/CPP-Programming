#include <iostream>
using namespace std;
int FMP(int arr[], int size)
{
    int s=1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==s)
        {
            s=arr[i]+1;
        }
    }
    
    return s;
}
int main()
{
    int arr[100];
    int user;
    cout << "Enter total elements: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << FMP(arr, user);

    return 0;
}
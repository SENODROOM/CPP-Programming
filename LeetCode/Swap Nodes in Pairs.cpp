#include <iostream>
using namespace std;
void swap(int arr[], int user)
{
    int newnum = user;
    if (user % 2 != 0)
    {
        newnum = user - 1;
    }
    for (int i = 0; i < newnum; i = i + 2)
    {
        int temp;
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    cout << "[";
    for (int i = 0; i < user; i++)
    {
        cout << arr[i];
        if (i<user-1)
        {
            cout << ",";
        }
    }
    cout << "]";
}
int main()
{
    int arr[100];
    int user;
    cout << "Enter total elements: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter element no " << i + 1 << ":";
        cin >> arr[i];
    }
    swap(arr, user);
}
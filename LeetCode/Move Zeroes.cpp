#include <iostream>
using namespace std;
void MZ(int arr[], int size)
{
    int count = 0;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            count++;
        else
            cout << arr[i];

        if (!((i == size - 1) && count == 0))
            cout << ",";
    }
    for (int i = 0; i < count; i++)
    {
        cout << 0;
        if (i != count - 1)
            cout << ",";
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
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    MZ(arr, user);
    return 0;
}
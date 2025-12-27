#include <iostream>
using namespace std;

void Transform(int arr[], int size)
{
    int even = 0;
    int odd = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    int i = 0;
    while (even > 0)
    {
        arr[i] = 0;
        i++;
        even--;
    }
    while (odd > 0)
    {
        arr[i] = 1;
        i++;
        odd--;
    }
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    int user, num;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }
    Transform(arr, user);
}

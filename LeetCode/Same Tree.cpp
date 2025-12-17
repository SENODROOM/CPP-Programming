#include <iostream>
using namespace std;

bool CHECK(int arr1[], int size1, int arr2[], int size2)
{
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

int main()
{
    int user;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }
    int user2;
    int arr2[200];
    cout << "Enter the size of your array: ";
    cin >> user2;
    for (int i = 0; i < user2; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr2[i];
    }
    if (CHECK(arr, user, arr2, user2))
        cout << "true";
    else
        cout << "false";
}
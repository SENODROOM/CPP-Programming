#include <iostream>
using namespace std;

int SingleNumber(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool check = true;
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == arr[j])
                check = false;
        }
        if (check)
            return arr[i];
    }
    return -1;
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
    cout << SingleNumber(arr, user);
}
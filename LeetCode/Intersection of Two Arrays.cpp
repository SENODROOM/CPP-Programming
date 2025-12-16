#include <iostream>
using namespace std;

void intersection(int arr1[], int size1, int arr2[], int size2)
{
    int check[100] = {0};
    int arr3[200];
    int size3 = 0;
    // Count elements in arr1
    for (int i = 0; i < size1; i++)
    {
        check[arr1[i]]++;
    }

    // Check elements in arr2
    for (int i = 0; i < size2; i++)
    {
        if (check[arr2[i]] > 0)
        {
            arr3[size3] = arr2[i];
            size3++;
            check[arr2[i]] = 0; // To avoid printing duplicates
        }
    }

    cout << "[";
    for (int i = 0; i < size3; i++)
    {
        cout << arr3[i];
        if (i != size3 - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    int arr[100], arr2[100];
    int user, user2;

    cout << "Enter total elements of first array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Enter total elements of second array: ";
    cin >> user2;
    for (int i = 0; i < user2; i++)
    {
        cout << "Enter arr2[" << i << "]: ";
        cin >> arr2[i];
    }

    cout << "Intersection: ";
    intersection(arr, user, arr2, user2);

    return 0;
}

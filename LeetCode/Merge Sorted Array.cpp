#include <iostream>
using namespace std;
void find(int arr1[], int size1, int arr2[], int size2)
{
    int arr3[200];
    for (int i = 0; i < size1; i++)
        arr3[i] = arr1[i];

    for (int i = size1; i < size1 + size2; i++)
        arr3[i] = arr2[i - size1];

    for (int j = 0; j < size1 + size2; j++)
    {
        for (int i = 0; i < size1 + size2; i++)
        {
            if (i != j)
            {
                if (arr3[i + 1] < arr3[i])
                {
                    int temp = arr3[i];
                    arr3[i] = arr3[i + 1];
                    arr3[i + 1] = temp;
                }
            }
        }
    }

    cout << "[";
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr3[i];
        if (i != size1 + size2 - 1)
        {
            cout << ',';
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
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    int arr2[100];
    int user2;
    cout << "Enter total elements: ";
    cin >> user2;
    for (int i = 0; i < user2; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr2[i];
    }
    find(arr, user, arr2, user2);

    return 0;
}
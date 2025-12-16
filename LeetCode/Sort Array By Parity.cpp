#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int user;
    cout << "Enter total elements of first array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }

    if (user > 1)
    {
        int count = user - 1;
        for (int i = 0; i < user && i <= count; i++)
        {

            if (arr[i] % 2 != 0)
            {
                int temp = arr[i];
                arr[i] = arr[count];
                arr[count] = temp;
                count--;
                i--;
            }
        }

        cout << "[";
        for (int i = 0; i < user; i++)
        {
            cout << arr[i];
            if (i != user - 1)
            {
                cout << ",";
            }
        }
        cout << "]";
    }
    else
    {
        cout << arr[0];
    }
}
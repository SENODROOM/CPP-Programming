#include <iostream>
using namespace std;
int main()
{
    int arr[100];
    int user;
    cout << "Enter the size of array: ";
    cin >> user;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < user; i++)
    {
        cin >> arr[i];
    }

    if (user > 1)
    {

        for (int i = 0; i < user - 1; i = i + 2)
        {

            if (arr[0] % 2 == 0)
            {
                if (arr[i + 1] % 2 == 0)
                {
                    for (int m = i + 2; m < user; m++)
                    {
                        if (arr[m] % 2 != 0)
                        {
                            int temp = arr[m];
                            arr[m] = arr[i + 1];
                            arr[i + 1] = temp;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (arr[i + 1] % 2 != 0)
                {
                    for (int m = i + 2; m < user; m++)
                    {
                        if (arr[m] % 2 == 0)
                        {
                            int temp = arr[m];
                            arr[m] = arr[i + 1];
                            arr[i + 1] = temp;
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < user; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {
        cout << arr[0];
    }
}
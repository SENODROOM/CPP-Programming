#include <iostream>
using namespace std;
void duplicate(int arr[], int user)
{
    int array[100];
    int count = 0;
    for (int i = 0; i < user; i++)
    {
        for (int j = i + 1; j < user; j++)
        {
            if (arr[i] == arr[j])
            {
                array[count] = arr[j];
                for (int k = j; k < user; k++)
                {
                    arr[k] = arr[k + 1];
                }

                user--;
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "Sorry no duplicate element is find";
    }
    else

    {
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (array[i] > array[j])
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        for (int i = 0; i < count; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (array[i] == array[j])
                {

                    for (int k = j; k < count; k++)
                    {
                        array[k] = array[k + 1];
                    }
                    count--;
                    j--;
                }
            }
        }

        cout << "[";
        for (int i = 0; i < count; i++)
        {
            cout << array[i];
            if (i == (count - 1))
                cout << ",";
        }
        cout << "]";
    }
}
int main()
{
    int arr[100];
    int user;
    cout << "Enter size of the array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter " << i + 1 << " element: ";
        cin >> arr[i];
    }
    duplicate(arr, user);
}
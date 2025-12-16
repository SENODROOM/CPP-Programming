#include <iostream>
using namespace std;
int TMN(int arr[], int size)
{
    int largest;
    if (size < 4)
    {
        for (int i = 0; i < size; i++)
        {
            if (!(largest) || arr[i] > largest)
                largest = arr[i];
        }
    }
    else
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if ((!(largest) || arr[i] > largest)&&count<4)
            {
                largest = arr[i];
                count++;
            }
        }
    }

    return largest;
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
    cout << TMN(arr, user);
    return 0;
}
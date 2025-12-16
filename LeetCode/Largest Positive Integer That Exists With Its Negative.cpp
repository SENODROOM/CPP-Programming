#include <iostream>
using namespace std;
int LPTEN(int arr[], int size)
{
    int largest;
    for (int i = 0; i < size; i++)
    {
        bool check = false;
        for (int j = 0; j < size; j++)
        {
            if (i != j && arr[i] == (-arr[j]))
                check = true;
        }
        if (check && (!(largest) || largest < arr[i]))
            largest = arr[i];
    }
    return largest;
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
    int result = LPTEN(arr, user);
    if (result)
    {
        cout << result;
    }
    else
    {
        cout << "NO PAIRS";
    }
}
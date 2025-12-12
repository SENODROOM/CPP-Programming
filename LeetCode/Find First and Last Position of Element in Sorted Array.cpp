#include <iostream>
using namespace std;
void find(int arr[], int size, int target)
{
    int first, last;
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            first = i;
            break;
        }
    }
    for (int i = size - 1; i > -1; i--)
    {
        if (target == arr[i])
        {
            last = i;
            break;
        }
    }
    if (first && last)
    {
        cout << "[" << first << "," << last << "]";
    }
    else
    {
        cout << "[" << -1 << "," << -1 << "]";
    }
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
    int target;
    cout << "Enter target: ";
    cin >> target;
    find(arr, user, target);

    return 0;
}
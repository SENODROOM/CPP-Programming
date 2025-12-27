#include <iostream>
#include <climits>
using namespace std;

int calculateExpression(int nums[], int size)
{
    if (size < 2)
        return 0;   // or handle error

    int highest = INT_MIN;
    int second  = INT_MIN;
    int lowest  = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] > highest)
        {
            second = highest;
            highest = nums[i];
        }
        else if (nums[i] > second && nums[i] <= highest)
        {
            second = nums[i];
        }

        if (nums[i] < lowest)
            lowest = nums[i];
    }

    return highest + second - lowest;
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

    cout << calculateExpression(arr, user);
    return 0;
}

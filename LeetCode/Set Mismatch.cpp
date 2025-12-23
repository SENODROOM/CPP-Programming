#include <iostream>
using namespace std;
void check(int arr[], int size)
{
    cout<<"[";
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
            cout << arr[i] << "," << arr[i] + 1;
    }
    cout<<"]";
}
int main()
{
    int arr[200], n;
    cout << "Enter total elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    check(arr, n);
    return 0;
}

// Example 1:

// Input: nums = [1,2,2,4]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1]
// Output: [1,2]
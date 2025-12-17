#include <iostream>
using namespace std;

bool containsNearbyDuplicate(int arr[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j] && (j - i) <= k)
                return true;
        }
    }
    return false;
}

int main()
{
    int n, k;
    int arr[100000];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    if (containsNearbyDuplicate(arr, n, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}

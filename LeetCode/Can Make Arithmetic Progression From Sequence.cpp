#include <iostream>
using namespace std;

bool check(int arr1[], int size1)
{
    if (size1 == 1)
        return true;
    int count = 0;
    int arr2[200];
    for (int i = 0; i < size1 - 1; i++)
    {
        for (int j = 0; j < size1 - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }
    int d = arr1[1] - arr1[0];
    for (int i = 1; i < size1; i++)
        if ((arr1[i] - arr1[i-1])!=d)
            return false;
    return true;
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
    if (check(arr, n))
        cout << "true";
    else
        cout << "false";
    return 0;
}






// Example 1:
// Input: arr = [3,5,1]
// Output: true
// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with 
// differences 2 and -2 respectively, between each consecutive elements.
// Example 2:
// Input: arr = [1,2,4]
// Output: false
// Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
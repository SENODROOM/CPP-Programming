#include <iostream>
using namespace std;

void removeelement(int arr[], int size, int k)
{
    int num = k % size;
    int arr2[200];
    int temp = 0;
    while (num > 0)
    {
        arr2[temp] = arr[size - num];
        temp++;
        num--;
    }
    for (int i = 0; i < size - k; i++)
    {
        arr2[temp] = arr[i];
        temp++;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i]=arr2[i];
    }
    
    cout << temp << endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << arr2[i];
        if (i < size - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    int user, num;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Enter k: ";
    cin >> num;
    removeelement(arr, user, num);
}





// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

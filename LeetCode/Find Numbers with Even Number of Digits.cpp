#include <iostream>
using namespace std;
int find(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        int digits = 0;
        while (arr[i] > 0)
        {
            arr[i] /= 10;
            digits++;
        }
        if (digits % 2 == 0)
            total++;
    }
    return total;
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
    cout << find(arr, user);
    return 0;
}



// Example 1:

// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.
// Example 2:

// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.
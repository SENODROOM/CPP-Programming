#include <iostream>
using namespace std;

int bestTime(int arr[], int size)
{
    int min = arr[0];
    int minI = 0;
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            minI = i;
        }
    }
    int max = arr[minI];
    for (int j = minI + 1; j < size; j++)
        if (max < arr[j])
            max = arr[j];
    return max-min;
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
    cout << bestTime(arr, user);
}

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

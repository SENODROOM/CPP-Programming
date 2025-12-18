#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return 0;

    bool isPrime = true;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}

int GP(int arr[][10], int n1)
{
    int greatest = arr[0][0];

    // Primary diagonal
    for (int k = 0; k < n1; k++)
        if (isPrime(arr[k][k]) && arr[k][k] > greatest)
            greatest = arr[k][k];

    // Secondary diagonal
    for (int k = 0; k < n1; k++)
        if (isPrime(arr[k][n1 - 1 - k]) && arr[k][n1 - 1 - k] > greatest)
            greatest = arr[k][k];

    return greatest;
}

int main()
{
    int arr[10][10];
    int n;
    cout << "Enter the n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }
    cout << GP(arr, n);

    return 0;
}

// Example 1:

// Input: nums = [[1,2,3],[5,6,7],[9,10,11]]
// Output: 11
// Explanation: The numbers 1, 3, 6, 9, and 11 are the only numbers present
// on at least one of the diagonals. Since 11 is the largest prime, we return 11.
// Example 2:

// Input: nums = [[1,2,3],[5,17,7],[9,11,10]]
// Output: 17
// Explanation: The numbers 1, 3, 9, 10, and 17 are all present on at least one of the diagonals.
// 17 is the largest prime, so we return 17.
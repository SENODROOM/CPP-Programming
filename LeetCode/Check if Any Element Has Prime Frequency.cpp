#include <iostream>
using namespace std;

/*
    FUNCTION: isPrime
    PURPOSE:
    --------
    Checks whether a given number is a prime number.

    A prime number:
    - Must be greater than 1
    - Has exactly two divisors: 1 and itself

    EXAMPLES:
    ----------
    isPrime(2)  -> true
    isPrime(3)  -> true
    isPrime(4)  -> false
    isPrime(1)  -> false
*/
bool isPrime(int num)
{
    // Prime numbers must be greater than 1
    if (num <= 1)
        return false;

    // Try dividing num by all numbers from 2 to num-1
    for (int i = 2; i < num; i++)
    {
        // If num is divisible by i, it is NOT prime
        if (num % i == 0)
            return false;
    }

    // If no divisors found, number is prime
    return true;
}

/*
    FUNCTION: check
    PURPOSE:
    --------
    Determines whether ANY element in the array
    has a PRIME frequency.

    PROCESS:
    --------
    - For each element:
        - Count how many times it appears in the array
        - Check if that frequency is prime
    - If at least one prime frequency is found → return true
    - Otherwise → return false
*/
bool check(int arr[], int size)
{
    // Loop through each element of the array
    for (int i = 0; i < size; i++)
    {
        int freq = 0;

        // Count frequency of arr[i]
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
                freq++;
        }

        // Check if this frequency is prime
        if (isPrime(freq))
            return true;
    }

    // If no prime frequency found
    return false;
}

int main()
{
    int arr[200];
    int n;

    cout << "Enter total elements: ";
    cin >> n;

    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    // Check and display result
    if (check(arr, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Example 1:
// Input: nums = [1,2,3,4,5,4]
// Output: true
// Explanation:
// 4 has a frequency of two, which is a prime number.

// Example 2:
// Input: nums = [1,2,3,4,5]
// Output: false
// Explanation:
// All elements have a frequency of one.

// Example 3:
// Input: nums = [2,2,2,4,4]
// Output: true
// Explanation:
// Both 2 and 4 have a prime frequency.
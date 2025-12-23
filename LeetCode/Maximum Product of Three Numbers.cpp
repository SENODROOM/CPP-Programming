#include <iostream>
using namespace std;

/*
Problem: Maximum Product of Three Numbers
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example:
Input: nums = [1,2,3,4]
Output: 24
Explanation: 2 * 3 * 4 = 24

Approach:
1. The maximum product of three numbers can come from:
   a) The product of the three largest positive numbers.
   b) The product of two smallest (most negative) numbers and the largest positive number.
2. To find this efficiently without sorting, we track:
   - The three largest numbers
   - The two smallest numbers (most negative)
3. Finally, calculate the maximum between:
   - product of three largest
   - product of two smallest and largest
*/

int maximumProduct(int arr[], int size) {
    // Edge case: array must have at least three elements
    if (size < 3) {
        cout << "Array must have at least three numbers." << endl;
        return -1; // Invalid input
    }

    // Initialize three largest numbers to minimum possible
    int max1 = -2147483648; // Largest
    int max2 = -2147483648; // Second largest
    int max3 = -2147483648; // Third largest

    // Initialize two smallest numbers to maximum possible
    int min1 = 2147483648; // Smallest
    int min2 = 2147483648; // Second smallest

    // Traverse the array once to find max1, max2, max3, min1, min2
    for (int i = 0; i < size; i++) {
        int num = arr[i];

        // Update the three largest numbers
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        // Update the two smallest numbers
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    // Maximum product can be either:
    // 1. Product of three largest numbers
    // 2. Product of two smallest numbers (possibly negative) and the largest number
    int product1 = max1 * max2 * max3;
    int product2 = max1 * min1 * min2;

    // Return the maximum of the two
    return (product1 > product2) ? product1 : product2;
}

// Helper function to print array (for explanation and testing)
void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) cout << ", ";
    }
    cout << "]";
}

int main() {
    int arr[200], n;
    cout << "Enter total elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << maximumProduct(arr, n);
    return 0;
}

// Example 1:

// Input: nums = [1,2,3]
// Output: 6
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:

// Input: nums = [-1,-2,-3]
// Output: -6

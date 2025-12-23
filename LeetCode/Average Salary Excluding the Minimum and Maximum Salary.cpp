#include <iostream>
using namespace std;

double average(int arr[], int size)
{
    int smallest = arr[0];
    int largest = arr[0];
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];

        if (arr[i] < smallest)
            smallest = arr[i];

        if (arr[i] > largest)
            largest = arr[i];
    }

    return (double)(sum - smallest - largest) / (size - 2);
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

    cout << average(arr, n);
    return 0;
}

// Example 1:

// Input: salary = [4000,3000,1000,2000]
// Output: 2500.00000
// Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
// Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500
// Example 2:

// Input: salary = [1000,2000,3000]
// Output: 2000.00000
// Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
// Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
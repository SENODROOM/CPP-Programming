#include <iostream>
using namespace std;

void RR(int arr[], int size)
{
    int rank[200];

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = 0; j < size; j++)
            if (i != j && arr[j] < arr[i])
                count++;

        rank[i] = count;
    }

    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << rank[i];

        if (i != size - 1)
            cout << ",";
    }
    cout << "]";
}
int main()
{
    int user;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }
    RR(arr, user);

    return 0;
}








// Example 1:

// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.
// Example 2:

// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.
// Example 3:

// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]
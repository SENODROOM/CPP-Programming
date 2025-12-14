// #include <iostream>
// using namespace std;
// int find(int arr[], int size, int target)
// {
//     int largest = arr[0];
//     int smallest = arr[0];
//     for (int i = 0; i < size; i++)
//     {
//         int count = 2;
//         for (int j = 0; j < size; j++)
//         {
//             if (i != j)
//             {
//                 int temp = arr[i] + arr[j];
//                 for (int k = 0; k < size; k++)
//                 {
//                     if (count == target)
//                     {
//                         count = 2;
//                         break;
//                     }
//                     if (k != j)
//                     {
//                         temp += arr[k];
//                         count++;
//                     }
//                 }
//                 if (temp > largest)
//                 {
//                     largest = temp;
//                 }
//                 if (temp < smallest)
//                 {
//                     smallest = temp;
//                 }
//             }
//         }
//     }
//     // cout << largest << " smallest " << smallest<<endl;
//     return (largest-smallest);
// }
// int main()
// {
//     int arr[100];
//     int user;
//     cout << "Enter total elements: ";
//     cin >> user;
//     for (int i = 0; i < user; i++)
//     {
//         cout << "Enter arr[" << i << "]: ";
//         cin >> arr[i];
//     }
//     int target;
//     cout << "Enter target: ";
//     cin >> target;
//     cout << find(arr, user, target);

//     return 0;
// }

#include <iostream>
using namespace std;

int n, target;
int arr[100];
int largest = -1000000000; // initialize to very small number
int smallest = 1000000000; // initialize to very large number

// Recursive function to find all sums of 'target' elements
void findSum(int index, int count, int sum)
{
    if (count == target)
    {
        if (sum > largest)
            largest = sum;
        if (sum < smallest)
            smallest = sum;
        return;
    }
    if (index == n)
        return;

    // Include current element
    findSum(index + 1, count + 1, sum + arr[index]);

    // Skip current element
    findSum(index + 1, count, sum);
}

int main()
{
    cout << "Enter total elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    findSum(0, 0, 0);

    cout << "Difference between largest and smallest sum: " << largest - smallest << endl;

    return 0;
}

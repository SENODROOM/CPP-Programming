#include <iostream>
using namespace std;

int Majority(int arr[], int n)
{
    /*
    This algorithm is called Boyer–Moore Majority Vote Algorithm.

    Idea:
    - A majority element appears more than n/2 times.
    - We keep one candidate (majority) and a counter.
    - Same value as candidate → increase count
    - Different value → decrease count
    - When count becomes 0, we change the candidate

    Reason:
    - Every different element cancels one occurrence of the candidate.
    - Since the majority element appears more than all others combined,
      it cannot be fully cancelled and will remain at the end.
    */

    int majority = arr[0];
    int count = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == majority)
            count++;
        else
            count--;

        if (count == 0)
        {
            majority = arr[i];
            count = 1;
        }
    }

    return majority;
}

int main()
{
    int arr[100];
    int n;

    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << Majority(arr, n);
    return 0;
}














// #include <iostream>
// using namespace std;
// int Majority(int arr1[], int size1)
// {
//     int majority = arr1[0];
//     int majoritycount = 0;
//     for (int i = 0; i < size1; i++)
//     {
//         int temp = arr1[i];
//         int count = 0;
//         for (int j = 0; j < size1; j++)
//         {
//             if (i != j && arr1[j] == temp)
//                 count++;
//         }
//         if (count >majoritycount)
//         {
//             majoritycount=count;
//             majority=arr1[i];
//         }
//     }

//     return majority;
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
//     cout << Majority(arr, user);

//     return 0;
// }
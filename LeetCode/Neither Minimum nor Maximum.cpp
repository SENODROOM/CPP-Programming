#include <iostream>
using namespace std;
int find(int arr[], int size)
{
    if (size < 3)
        return -1;

    // for (int i = 1; i < size; i++)
    // {
    //     if (!(value == arr[i]))
    //     {
    //         count++;
    //         if (count == 2)
    //         {
    //             if (max < arr[i])
    //             {
    //                 if (arr[0] > arr[1])
    //                     return arr[0];
    //                 else
    //                     return arr[1];
    //             }
    //             else
    //             {
    //                 if (max > arr[0])
    //                 {
    //                     return arr[0];
    //                     return arr[2];
    //                 }
    //             }
    //         }
    //         value = arr[i];
    //         if (max < arr[i])
    //             max = arr[i];
    //     }
    // }
    // int max = arr[0];
    // if (max < arr[1])
    //     max = arr[1];

    // if (max > arr[2])
    // {
    //     if (arr[2] > arr[0])
    //         return arr[2];
    //     else
    //         return arr[1];
    // }
    // else
    // {
    //     if (arr[1] > arr[0])
    //         return arr[1];
    //     else
    //         return arr[0];
    // }
    int a = arr[0], b = arr[1], c = arr[2];
    if (a > b)
    {
        if (a > c)
        {
            if (b > c)
            {
                return b;
            }
            else
            {
                return c;
            }
        }
        else
        {
            if (a > c)
            {
                return c;
            }
            else
            {
                return a;
            }
        }
    }
    else
    {
        if (b > c)
        {
            if (a > c)
            {
                return a;
            }
            else
            {
                return c;
            }
        }
        else
        {
            if (a > b)
            {
                return a;
            }
            else
            {
                return b;
            }
        }
    }

    return -1;
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
#include <iostream>
using namespace std;

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

bool containsDuplicate(int arr[], int n) {
    sortArray(arr, n);
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1])
            return true;
    }
    return false;
}

int main() {
    int arr[100];
    int n;
    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    if (containsDuplicate(arr, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}


// ================================(SLOWER VERSION):
// #include <iostream>
// using namespace std;
// bool find(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = 0; j < size; j++)
//         {
//             if (j != i &&
//                 arr[i] == arr[j])
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
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
//     if (find(arr, user))
//     {
//         cout << "true";
//     }
//     else
//     {
//         cout << "false";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

void check(int arr1[], int size1, int target)
{
    // ---------- SORT ARRAY (Selection Sort) ----------
    for (int i = 0; i < size1 - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size1; j++)
        {
            if (arr1[j] < arr1[minIndex])
                minIndex = j;
        }

        // swap
        int temp = arr1[i];
        arr1[i] = arr1[minIndex];
        arr1[minIndex] = temp;
    }

    // ---------- FIND TARGET INDICES ----------
    int arr2[200];
    int size2 = 0;   // ✅ initialized

    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] == target)
        {
            arr2[size2] = i;
            size2++;
        }
    }

    // ---------- OUTPUT ----------
    cout << "[";
    for (int i = 0; i < size2; i++)
    {
        cout << arr2[i];
        if (i != size2 - 1)
            cout << ",";
    }
    cout << "]";
}

int main()
{
    int arr[200], n, target;

    cout << "Enter total elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    check(arr, n, target);
    return 0;
}

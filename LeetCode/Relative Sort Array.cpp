#include <iostream>
using namespace std;

void relativesort(int arr1[], int size1, int arr2[], int size2)
{
    int count = 0;
    cout << "[";
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            if (arr2[i] == arr1[j])
            {
                cout << arr1[j];
                count++;
                if (count != size1-1)
                    cout << ",";
            }
        }
    }
    for (int i = 0; i < size1; i++)
    {
        bool check = true;
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                check = false;
                break;
            }
        }
        if (check)
        {
            cout << arr1[i];
            if (i != size1-1)
                cout << ",";
        }
    }
    cout << "]";
}

int main()
{
    int g[100], s[100];
    int n, m;

    cout << "Enter size of arr1: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> g[i];
    }

    cout << "Enter size of arr2: ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter arr2[" << i << "]: ";
        cin >> s[i];
    }
    relativesort(g, n, s, m);
}

// Example 1:

// Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// Output: [2,2,2,1,4,3,3,9,6,7,19]
// Example 2:

// Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// Output: [22,28,8,6,17,44]

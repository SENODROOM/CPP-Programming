#include <iostream>
using namespace std;

void RR(int arr[], int size)
{
    int rank[200];

    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = 0; j < size; j++)
            if (i != j && arr[j] > arr[i])
                count++;

        rank[i] = count;
    }

    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (rank[i] == 1)
            cout << "Gold Medal";
        else if (rank[i] == 2)
            cout << "Silver Medal";
        else if (rank[i] == 3)
            cout << "Bronze Medal";
        else
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
#include <iostream>
using namespace std;

int arr2[200];
int size2 = 0;

void Convert(int arr[], int start, int end)
{
    if (start > end)
        return;

    int mid = start + (end - start) / 2;

    arr2[size2++] = arr[mid]; 

    Convert(arr, start, mid - 1); 
    Convert(arr, mid + 1, end);  
}

int main()
{
    int arr[100];
    int user;

    cout << "Enter total elements: ";
    cin >> user;

    cout << "Enter sorted elements:\n";
    for (int i = 0; i < user; i++)
        cin >> arr[i];

    Convert(arr, 0, user - 1);

    cout << "\nBST (Preorder): ";
    for (int i = 0; i < size2; i++)
        cout << arr2[i] << " ";

    return 0;
}

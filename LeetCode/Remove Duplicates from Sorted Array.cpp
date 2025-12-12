#include <iostream>
using namespace std;

void combinesort(int arr[], int size)
{
    for (int k = 0; k < size; k++)
    {
        for (int m = k + 1; m < size; m++)
        {
            if (arr[m] < arr[k])
            {
                int temp = arr[k];
                arr[k] = arr[m];
                arr[m] = temp;
            }
        }
    }

    int arr2[200];
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        bool check = true;
        for (int j = 0; j < temp; j++)
        {
            if (arr[i] == arr[j])
            {
                check = false;
            }
        }
        if (check)
        {
            arr2[temp] = arr[i];
            temp++;
        }
    }
    cout << temp<<endl;
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        if (i<temp)
        {   
            cout << arr2[i];
        }
        else{
            cout<<"_";
        }
        if (i < size - 1)
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
    combinesort(arr, user);
}
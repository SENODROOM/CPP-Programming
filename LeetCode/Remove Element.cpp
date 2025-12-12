#include <iostream>
using namespace std;

void removeelement(int arr[], int size,int num)
{
    int arr2[200];
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]!=num)
        {
            arr2[temp] = arr[i];
            temp++;
        }
    }
    cout << temp << endl;
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
    int user,num;
    int arr[200];
    cout << "Enter the size of your array: ";
    cin >> user;
    for (int i = 0; i < user; i++)
    {
        cout << "Enter arr1[" << i << "]: ";
        cin >> arr[i];
    }
    cout << "Enter element to remove: ";
    cin >> num;
    removeelement(arr, user,num);
}

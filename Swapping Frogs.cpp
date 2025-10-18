#include <iostream>
using namespace std;


void printarray(int arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != -1)
        {
            cout << arr[i] << " ";
        }
        else
        {
            cout << "_" << " ";
        }
    }
    cout<< endl;
}
void swaptwoelements(int arr[], int n1, int n2, int size)
{
    int temp1 = arr[n1];
    int temp2 = arr[n2];
    for (int i = 0; i < size; i++)
    {
        if (i == n1)
        {
            arr[i] = temp2;
        }
        if (i == n2)
        {
            arr[i] = temp1;
        }
    }
    printarray(arr , size);
}

int main()
{
    int arr[] = {0, 0, 0, -1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(int);

    printarray(arr,n);
    swaptwoelements( arr , 2 , 3, n );
    swaptwoelements( arr , 4 , 2, n );
    swaptwoelements( arr , 4 , 5, n );
    swaptwoelements( arr , 3 , 5, n );
    swaptwoelements( arr , 1 , 3, n );
    swaptwoelements( arr , 0 , 1, n );
    swaptwoelements( arr , 2 , 0, n );
    swaptwoelements( arr , 2 , 4, n );
    swaptwoelements( arr , 4 , 6, n );
    swaptwoelements( arr , 5 , 6, n );
    swaptwoelements( arr , 3 , 5, n );
    swaptwoelements( arr , 1 , 3, n );
    swaptwoelements( arr , 1 , 2, n );
    swaptwoelements( arr , 2 , 4, n );
    swaptwoelements( arr , 3 , 4, n );
    cout << "Total Moves: " << 15;
}

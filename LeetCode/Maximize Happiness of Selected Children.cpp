#include <iostream>
#include <algorithm>
using namespace std;
int find(int happiness[], int size, int k)
{
    sort(happiness,happiness+size);
    int count=0,result=0;
    for (int i = k; i>0; i--)
    {
        result += ((happiness[size-1-count]-count)>0)?(happiness[size-1-count]-count):(0) ;
        count++;
    }
    return result;
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
    int k;
    cout << "Enter k: ";
    cin >> k;
    cout << find(arr, user, k);
    return 0;
}
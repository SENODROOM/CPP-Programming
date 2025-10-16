#include <iostream>
using namespace std;
int binarySearch(int arr[], int size,int ele)
{
    int mid, start = 0, end = size - 1;
    while (start <= end)
    {
        cout << "finding mid" << endl;
        mid = (start + end) / 2;
        if (arr[mid] == ele)
        {
            cout << "value found" << endl;
            return mid;
        }
        else if (ele > arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main()
{
    int list[] = { 2,4,7,8,9,11,12,13,14,55,78,88,99,100 };
    int size = sizeof(list) / 4;
    cout << binarySearch(list, size, 4);
}
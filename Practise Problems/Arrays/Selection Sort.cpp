#include <iostream>
using namespace std;
void selectionSort(int arr[], int size)
{
    int min, minind;
    for (int i = 0; i < size; i++)
    {
        min = arr[i];
        minind = i;
        for (int j = i+1; j < size; j++)
        {
            if (min > arr[j]) {
                min = arr[j];
                minind = j;
            }
        }
        cout << "Minimum value is " << min << " at index " << minind << endl;
        cout << "Swapping index" << i << " and " << minind << endl;
        int temp=arr[i];
        arr[i] = min;
        arr[minind] = temp;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int list[] = { 5,1,4,3,2};
    int size = sizeof(list) / 4;
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
    selectionSort(list, size);
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}
#include <iostream>
using namespace std;

int globalcount;

int *mergeArray(int arr1[], int s1, int arr2[], int s2)
{
    static int mergedArray[200];
    for (int i = 0; i < (s1 + s2); i++)
    {
        if (i >= s1)
        {
            mergedArray[i] = arr2[i - s1];
        }
        else
        {
            mergedArray[i] = arr1[i];
        }
    }

    int count = 0;
    for (int i = 0; i < s1 + s2; i++)
    {
        int unique = 0;
        for (int j = 0; j < i; j++)
        {
            if (mergedArray[j] == mergedArray[i])
            {
                unique++;
            }
        }
        if (unique == 0)
        {
            count++;
        }
    }

    static int mergedremArray[200];
    int temp = 0;

    for (int i = 0; i < s1 + s2; i++)
    {
        int unique = 0;
        for (int j = 0; j < i; j++)
        {
            if (mergedArray[j] == mergedArray[i])
            {
                unique++;
            }
        }
        if (unique == 0)
        {
            mergedremArray[temp] = mergedArray[i];
            temp++;
        }
    }

    globalcount = count;
    return mergedremArray;
}

int *sortedArray(int arr[], int size)
{
    static int sortedArray[200];
    int temp = 0;

    // Copy original array
    for (int i = 0; i < size; i++)
    {
        sortedArray[i] = arr[i];
    }

    // Sorting
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (sortedArray[i] > sortedArray[j])
            {
                int t = sortedArray[i];
                sortedArray[i] = sortedArray[j];
                sortedArray[j] = t;
            }
        }
    }

    return sortedArray;
}

float median(int arr[], int size)
{
    int med;
    float value;
    if (size % 2 == 0)
    {
        med = size / 2;
        value = (arr[med] + arr[med - 1]) / 2.00;
    }
    else
    {
        med = size / 2;
        value = (arr[med]);
    }
    return value;
}

int main()
{
    int size1, size2;
    cout << "Enter the size of array 1: ";
    cin >> size1;

    int arr1[size1];
    for (int i = 0; i < size1; i++)
    {
        cout << "Enter the Value: ";
        cin >> arr1[i];
    }

    cout << "Enter the size of array 2: ";
    cin >> size2;

    int arr2[size2];
    for (int i = 0; i < size2; i++)
    {
        cout << "Enter the Value: ";
        cin >> arr2[i];
    }

    int *mergearray = mergeArray(arr1, size1, arr2, size2);
    int *sorteArray = sortedArray(mergearray, globalcount);

    cout << "Sorted Array: [";
    for (int i = 0; i < globalcount; i++)
    {
        cout << sorteArray[i];
        if(i!=(globalcount-1)){
            cout<<",";
        }
    }
    cout << "] and median is " << median(sorteArray,globalcount);
}

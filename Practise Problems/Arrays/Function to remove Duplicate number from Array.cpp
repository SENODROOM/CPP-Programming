#include <iostream>
using namespace std;

int main()
{
    cout << "Array before removing duplicates: ";
    int arr[] = {4, 2, 9, 2, 4, 5, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    


    int index = 0;
    for (int i = 0; i < n; i++)
    {
        bool isDuplicate = false;
        for (int j = 0; j < index; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate)
        {
            arr[index] = arr[i];
            index++;
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < index; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
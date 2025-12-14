#include <iostream>
using namespace std;

// height = [0,1,0,2,1,0,1,3,2,1,2,1]
int FRW(int arr[], int size)
{
    int first = 0;  // current left bar
    int fi = 0;     // index of current left bar
    int result = 0;

    // find the first non-zero bar
    int i = 0;
    while (i < size && arr[i] == 0)
        i++;
    if (i == size) return 0; // all zeros
    first = arr[i];
    fi = i;
    i++;

    while (i < size)
    {
        bool check = false;
        int found = i;

        // look for a bar >= first
        for (int j = fi + 1; j < size; j++)
        {
            if (arr[j] >= first)
            {
                for (int k = fi + 1; k < j; k++)
                {
                    result += (first - arr[k]);
                }
                fi = j;
                first = arr[j];
                check = true;
                break;
            }
        }

        if (!check)
        {
            // no bar >= first, find the max bar to the right
            int maxHeight = 0, maxIndex = fi + 1;
            for (int j = fi + 1; j < size; j++)
            {
                if (arr[j] > maxHeight)
                {
                    maxHeight = arr[j];
                    maxIndex = j;
                }
            }

            for (int k = fi + 1; k < maxIndex; k++)
            {
                result += (maxHeight - arr[k]);
            }

            fi = maxIndex;
            first = arr[maxIndex];
            i = fi + 1;
        }
        else
        {
            i = fi + 1;
        }
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

    cout << "Trapped water: " << FRW(arr, user);

    return 0;
}

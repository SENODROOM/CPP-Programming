#include <iostream>
using namespace std;

bool isDuplicate(int res[][3], int resSize, int a, int b, int c)
{
    for (int i = 0; i < resSize; i++)
    {
        int x = res[i][0], y = res[i][1], z = res[i][2];
        if ((a == x || a == y || a == z) &&
            (b == x || b == y || b == z) &&
            (c == x || c == y || c == z))
        {
            return true;
        }
    }
    return false;
}

void Sum3Close(int arr[], int size, int target)
{
    int res[100][3];
    int resSize = 0;
    int closestSum = arr[0] + arr[1] + arr[2];
    int minDiff = abs(target - closestSum);

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++) 
            {
                int sum = arr[i] + arr[j] + arr[k];
                int diff = abs(target - sum);
                
                if (diff < minDiff) 
                {
                    minDiff = diff;
                    closestSum = sum;
                    resSize = 0;
                    res[resSize][0] = arr[i];
                    res[resSize][1] = arr[j];
                    res[resSize][2] = arr[k];
                    resSize++;
                }
                else if (diff == minDiff && !isDuplicate(res, resSize, arr[i], arr[j], arr[k]))
                {
                    res[resSize][0] = arr[i];
                    res[resSize][1] = arr[j];
                    res[resSize][2] = arr[k];
                    resSize++;
                }
            }
        }
    }

    cout << "Closest sum to target " << target << " is: " << closestSum << endl;
    cout << "Triplets giving this sum:" << endl;
    for (int i = 0; i < resSize; i++)
    {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
}

int main()
{
    int arr[] = {-1,2,1,-4};
    Sum3Close(arr, 4, 1);
    return 0;
}
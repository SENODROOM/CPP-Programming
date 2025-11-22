#include <iostream>
using namespace std;

bool isDuplicate(int res[][4], int resSize, int a, int b, int c, int d)
{
    for (int i = 0; i < resSize; i++)
    {
        int x = res[i][0], y = res[i][1], z = res[i][2], w = res[i][3];
        if ((a == x || a == y || a == z || a == w) &&
            (b == x || b == y || b == z || b == w) &&
            (c == x || c == y || c == z || c == w) &&
            (d == x || d == y || d == z || d == w))
        {
            return true;
        }
    }
    return false;
}

void Sum4(int arr[], int size, int target)
{
    int res[100][4];
    int resSize = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                for (int z = k + 1; z < size; z++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[z] == target)
                    {
                        int a = arr[i], b = arr[j], c = arr[k], d = arr[z];
                        if (!isDuplicate(res, resSize, a, b, c, d))
                        {
                            res[resSize][0] = a;
                            res[resSize][1] = b;
                            res[resSize][2] = c;
                            res[resSize][3] = d;
                            resSize++;
                            cout << "[" << a << "," << b << "," << c << "," << d << "]" << endl;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int arr[] = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Sum4(arr, 6, target);
    return 0;
}
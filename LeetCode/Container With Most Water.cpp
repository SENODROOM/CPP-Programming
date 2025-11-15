#include <iostream>
using namespace std;

int findArea(int a, int b, int distance)
{
    return min(a, b) * distance;
}

int LargestArea(int arr[], int size){
    int maxArea = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            int area = findArea(arr[i], arr[j], j - i);
            if (area > maxArea)
            {
                maxArea = area;
            }
        }
    }
    return maxArea;
}

int main()
{
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int n = sizeof(height)/sizeof(int);
    cout << LargestArea(height, n);
    return 0;
}

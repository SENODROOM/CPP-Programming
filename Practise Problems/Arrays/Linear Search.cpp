#include <iostream>
using namespace std;

int linearSearch(int arr[], int size , int digit){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==digit)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int list[] = { 2,4,7,8,9,11,12,13,14,55,78,88,99,100 };
    int size = sizeof(list) / sizeof(int);
    cout << linearSearch(list, size, 14);
}
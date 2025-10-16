#include <iostream>
using namespace std;
int findMin(int arr[], int s)//by default by reference pass
{
    int min = arr[0];
    for (int i = 1; i <= s - 1; i++)
    {
        if (min > arr[i]) {
            min = arr[i];
        }
    }
    return min;
}
int main(){
    int marks[] = { 13,5,4,6};
    int size=sizeof(marks) / sizeof(int);
    cout << "Minimum = " << findMin(marks, size);
   
}
#include <iostream>
using namespace std;
void reverse(int arr[], int s)//by default by reference pass
{
    int temp;
    for (int i = 0,j=s-1; i < s/2; i++,j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main(){
    int marks[] = { 13,5,4,6};//{6,4,5,13}
    int size=sizeof(marks) / sizeof(int);
    reverse(marks, size);
    for (int i = 0; i < size; i++)
    {
        cout << marks[i]<<" ";
    }
}
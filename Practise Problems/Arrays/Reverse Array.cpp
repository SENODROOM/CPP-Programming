#include <iostream>
using namespace std;
int* reverse(int arr[], int s)//by default by reference pass
{
    static int reverse[4];//to extend its lifetime
    for (int i = 0,j=s-1; i < s; i++,j--)
    {
        reverse[j] = arr[i];
    }
    return reverse;
}
int main(){
    int marks[] = { 13,5,4,6};
    int size=sizeof(marks) / sizeof(int);
    int* rever = reverse(marks, size);
    for (int i = 0; i < size; i++)
    {
        cout << rever[i] << " ";
    }

   
}
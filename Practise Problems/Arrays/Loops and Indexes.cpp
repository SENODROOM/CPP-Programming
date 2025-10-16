#include <iostream>
using namespace std;
void print(int arr[])
{
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        arr[i]++;
        cout << &arr[i]<<endl;
    }
}
int main(){
    int marks[5] = {6,5};
    //cout << marks << endl;
    print(marks);
    for (int i = 0; i < 5; i++)
    {
        cout << "value for index " << i << " is " <<marks[i]<<" " << &marks[i] << endl;
    }
       
}
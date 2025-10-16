#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i]++;
        cout << &arr[i]<<endl;
    }

}
int main(){
    int marks[5] = {6,5};
    int s=sizeof(marks)/sizeof(int);
    cout << marks << endl;
    print(marks, s);

    for (int i = 0; i < s; i++)
    {
        cout << "value for index " << i << " is " <<marks[i]<<" " << &marks[i] << endl;
    }
       
}
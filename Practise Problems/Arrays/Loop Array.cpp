#include <iostream>
using namespace std;
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "value for index " << i << " is " << arr[i] << endl;
    }

}
int main(){
    int marks[5] = {6,5};
    int s=sizeof(marks)/sizeof(int);
    cout << marks << endl;
    print(marks, s);
   
       
}
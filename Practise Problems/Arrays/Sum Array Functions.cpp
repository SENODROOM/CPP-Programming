#include <iostream>
using namespace std;
void print(int arr[])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum+=arr[i];
    }
    cout << "sum " << sum << endl;
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
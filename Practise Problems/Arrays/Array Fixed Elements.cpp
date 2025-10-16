#include <iostream>
using namespace std;
int main(){
    int marks[5];
    int size;
    cin >> size;
    int s=sizeof(marks)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        cout << "Input value for index " << i << endl;
        cin >> marks[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "value for index " << i << " is " << marks[i] << endl;
    }
       
}
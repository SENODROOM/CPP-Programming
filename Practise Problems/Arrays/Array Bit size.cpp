#include <iostream>
using namespace std;
int main(){
    int marks[5];
    int s=sizeof(marks)/sizeof(int);
    
    cout << sizeof(marks) <<endl;
    cout << sizeof(int) <<endl;
    cout << s << endl;
    for (int i = 0; i < s; i++)
    {
        cout << "Input value for index " << i << endl;
        cin >> marks[i];
    }
    for (int i = 0; i < s; i++)
    {
        cout << "value for index " << i << " is " << marks[i] << endl;
    }
       
}
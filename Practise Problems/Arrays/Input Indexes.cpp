#include <iostream>
using namespace std;
int main()
{
    int marks[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Input value for index " << i << endl;
        cin >> marks[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "value for index " << i << " is " << marks[i] << endl;
    }
       
}
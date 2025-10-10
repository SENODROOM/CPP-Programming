#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num = 0, limit = 1;
    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the Limit: ";
    cin >> limit;
    for (int i = 1; i <= limit; i++)
    {
        cout << num << " * " << i << " = " << num*i << endl;
    }
    
}
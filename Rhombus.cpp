#include <iostream>
using namespace std;
int main()
{
    int n=0 , count=0;
    cout << "Number of rows: ";
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < (i-1); j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= count; k++)
        {
            cout << "*";
        }
        count= count + 2;
        
        cout << endl;
    }
    count = count - 2;
    for (int i = 0; i < n; i++)
    {
        count= count - 2;
        for (int j = 0; j < (i+1); j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= count; k++)
        {
            cout << "*";
        }
        
        cout << endl;
    }
}
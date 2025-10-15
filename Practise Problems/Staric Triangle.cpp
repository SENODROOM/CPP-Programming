#include <iostream>
using namespace std;
int main() {
    int ln;
    cin >>ln;
    for (int i = ln; i >=1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
   
    cout << "end";
}
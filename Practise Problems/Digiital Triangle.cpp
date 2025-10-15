#include <iostream>
using namespace std;
int main() {
    int ln;
    cin >>ln;
    for (int i = 1; i <= ln; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j<<"  ";
        }
        cout << endl;
    }
   
    cout << "end";
}
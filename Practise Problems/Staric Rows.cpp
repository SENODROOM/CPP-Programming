#include <iostream>
using namespace std;
int main() {
    int n,ln;
    cin >> n>>ln;
    for (int i = 1; i <= ln; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
   
    cout << "end";
}
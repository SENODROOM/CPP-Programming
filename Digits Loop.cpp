#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int line;
    cin >> line;
    int k = line;
    for (int i = line; i >=1; i--)
    {
        k = line;
        for (int j = 1; j <= line; j++){
            cout << k << " ";
            if (k > i)
            {
                k--;
            }
        }
        cout << endl;
    }
   
}
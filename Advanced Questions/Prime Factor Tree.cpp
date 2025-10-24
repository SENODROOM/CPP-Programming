#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int line;
    cin >> line;
    int k = 1;
    for (int i = 1; i <= line; i++)
    {
        for (int s = i; s <= line - 1; s++)
            cout <<setw(3)<< " ";
        for (int j = 1; j <= i; j++)
            cout << setw(3)<<k<<"  ";
        cout << endl;
        k += 2;
    }
   
}
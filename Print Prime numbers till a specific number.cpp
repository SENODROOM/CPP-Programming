#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, count = 0;
    cout << "Print How many prime numbers? ";
    cin >> n;
    for (int i = 2; i < (n * 10); i++)
    {
        int factor = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                factor++;
            }
        }
        if (factor == 2)
        {
            count++;
            cout << i << endl;
        }
        if(count==n){
            break;
        }
    }
}
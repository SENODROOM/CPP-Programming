#include <iostream>
#include<iomanip>
using namespace std;
int main() {
    int n,d=2;
    bool flag = false;
    cin>> n;
    if (n >= 2)
    {
        while (d < n && !flag)
        {
            if (n % d == 0)
            {
                flag = true;
                cout << "not prime" << endl;
            }
            d++;
        }
        if (flag == false)
            cout << "prime" << endl;

    }
    else {
        cout << "Not prime" << endl;
    }
   
}
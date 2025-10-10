#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int rev=0;
    for (int rem=0; n > 0; n = n / 10)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
    }
    cout << rev;
}
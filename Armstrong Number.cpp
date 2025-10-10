#include <iostream>
using namespace std;
int main() {
    int i = 3, n, sum, f = 0, s = 1;
    cin >> n;
    cout << f << "," << s << ",";
    while (i <= n)
    {
        sum = f + s;
        cout << sum << ",";
        f = s;
        s = sum;
        i++;
    }
}
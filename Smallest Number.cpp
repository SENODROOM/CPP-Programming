#include <iostream>
using namespace std;
int main() {
    int s,e, d,f;
    cin >> s>>e;
    while (s <= e) {
        d = 2;
        f = -1;
        while (d < s)
        {
            if (s % d == 0)
                f = 1;
            d++;
        }
        if (f == -1)
            cout << s << ",";
        s++;
    }
}
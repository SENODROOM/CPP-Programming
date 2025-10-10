#include <iostream>
using namespace std;
int main() {
    int n;
    do {
        cin >> n;
        (n < 0) ? (cout << "-") : ((n > 0) ? cout << "+" : cout << "0");
        cout << endl;
    } while (1);
    return 0;
}
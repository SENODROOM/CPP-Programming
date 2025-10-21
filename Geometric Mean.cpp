#include <iostream>
using namespace std;

int main() {
    int r, n;
    cout << "Enter common ratio (r): ";
    cin >> r;
    cout << "Enter number of terms (n): ";
    cin >> n;

    int term = 1, S = 0;
    for (int i = 0; i < n; i++) {
        S = term + S;
        term *= r;
    }
    cout << "Sum = " << S << endl;
    return 0;
}
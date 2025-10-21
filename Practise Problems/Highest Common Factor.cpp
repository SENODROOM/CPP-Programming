#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a number: ";
    cin >> a;
    cout << "Enter a number: ";
    cin >> b;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD (HCF) is: " << a << endl;
    return 0;
}
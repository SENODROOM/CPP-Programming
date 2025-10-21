#include <iostream>
using namespace std;

int main() {
    int num, originalNum, remainder, n = 0, result = 0;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;
    int temp = num;
    while (temp != 0) {
        temp /= 10;
        ++n;
    }
    temp = num;
    while (temp != 0) {
        remainder = temp % 10;
        int power = 1;
        int i = 0;
        while (i < n) {
            power *= remainder;
            i++;
        }

        result += power;
        temp /= 10;
    }

    if (result == originalNum)
        cout << originalNum << " is an Armstrong number." << endl;
    else
        cout << originalNum << " is not an Armstrong number." << endl;

    return 0;
}

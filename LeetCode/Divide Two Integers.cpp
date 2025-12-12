#include <iostream>
using namespace std;

int quotient(int dividend, int divisor) {
    if (divisor == 0) {
        cout << "Division by zero error!" << endl;
        return 0;
    }
    bool sign = ( (dividend < 0) == (divisor < 0) );
    if (dividend < 0) dividend = -dividend;
    if (divisor < 0) divisor = -divisor;
    int truncated = 0;
    int sum = 0;
    while (sum + divisor <= dividend) {
        sum += divisor;
        truncated++;
    }
    return sign ? truncated : -truncated;
}

int main() {
    int dividend, divisor;
    cout << "Enter dividend: ";
    cin >> dividend;
    cout << "Enter divisor: ";
    cin >> divisor;

    cout << quotient(dividend, divisor) << endl;
    return 0;
}
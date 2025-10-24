#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cout << "Enter upper limit: ";
    cin >> N;

    cout << "Armstrong numbers: ";

    for (int num = 100; num <= N; num++) {
        int temp = num;
        int digits = 0;

        while (temp > 0) {
            digits++;
            temp /= 10;
        }

        temp = num;
        int sum = 0;

        while (temp > 0) {
            int digit = temp % 10;
            sum += pow(digit, digits);
            temp /= 10;
        }

        if (sum == num)
            cout << num << " ";
    }

    cout << endl;
    return 0;
}

#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Enter number: ";
    cin >> N;

    cout << "Prime factors = ";
    for (int i = 2; i <= N; i++) {
        while (N % i == 0 && isPrime(i)) {
            cout << i << " ";
            N /= i;
        }
    }
    cout << endl;
    return 0;
}
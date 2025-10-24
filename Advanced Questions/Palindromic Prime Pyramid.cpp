#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of palindromic primes (n): ";
    cin >> n;

    int found = 0;   // how many palindromic primes we’ve printed
    int num = 2;     // current number to test
    int row = 1;     // current pyramid row

    while (found < n) {
        // ---------- Check Prime ----------
        bool prime = true;
        if (num < 2) prime = false;
        for (int i = 2; i * i <= num && prime; i++) {
            if (num % i == 0)
                prime = false;
        }

        // ---------- Check Palindrome ----------
        if (prime) {
            int temp = num, rev = 0, digit;
            while (temp > 0) {
                digit = temp % 10;
                rev = rev * 10 + digit;
                temp /= 10;
            }

            if (rev == num) {
                // ---------- Print in pyramid pattern ----------

                // Print leading spaces for each new row
                int required = row * (row + 1) / 2; // total elements after this row
                if (found == (row * (row - 1)) / 2) {
                    for (int s = 0; s < n - row; s++)
                        cout << "  ";
                }

                cout << num << " ";
                found++;

                // Check if row is complete
                if (found == required || found == n) {
                    cout << endl;
                    row++;
                }
            }
        }
        num++;
    }

    return 0;
}

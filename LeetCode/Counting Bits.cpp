#include <iostream>
using namespace std;

// Convert decimal to binary (as int)
int decimalToBinary(int n) {
    int binary = 0;
    int place = 1;

    while (n > 0) {
        int remainder = n % 2;
        binary += remainder * place;
        n = n / 2;
        place *= 10;
    }

    return binary;
}

// Compute sum of binary digits for 0 to size
void find(int size) {
    cout << "[";
    for (int count = 0; count <= size; count++) {
        int bin = decimalToBinary(count);
        int total = 0;

        // Sum the digits of binary number
        while (bin > 0) {
            total += bin % 10;
            bin /= 10;
        }

        cout << total;
        if (count != size) // Fix the last comma
            cout << ",";
    }
    cout << "]";
}

int main() {
    int user;
    cout << "Enter number: ";
    cin >> user;

    find(user);
    return 0;
}

// Example 1:

// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// Example 2:

// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
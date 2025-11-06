#include <iostream>
using namespace std;

void counter() {
    static int count = 0; // Initialized only once
    cout << "Count: " << count << endl;
    count++;
}

int main() {
    counter(); // Count: 1
    counter(); // Count: 2
    counter(); // Count: 3
}

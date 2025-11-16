#include <iostream>
using namespace std;

int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int total = 0;

    for (int i = 0; i < s.length(); i++) {
        int current = value(s[i]);
        int next = (i + 1 < s.length()) ? value(s[i + 1]) : 0;

        // Subtractive notation case
        if (current < next) {
            total -= current;
        } else {
            total += current;
        }
    }

    return total;
}

int main() {
    string roman;
    cout << "Enter Roman numeral: ";
    cin >> roman;

    cout << "Integer value: " << romanToInt(roman) << endl;
    return 0;
}

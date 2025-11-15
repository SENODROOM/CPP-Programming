#include <iostream>
using namespace std;

void IntegertoRoman(int num) {
    cout << "Roman: ";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            cout << symbols[i];
            num -= values[i];
        }
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter the Integer: ";
    cin >> num;

    if (num <= 0) {
        cout << "Roman numerals only support positive integers!" << endl;
    } else {
        IntegertoRoman(num);
    }

    return 0;
}

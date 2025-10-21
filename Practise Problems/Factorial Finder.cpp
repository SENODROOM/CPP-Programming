#include <iostream>
using namespace std;

int main() {
    int num, choice = 1;

    while (choice == 1) {
        cout << "Enter a number: ";
        cin >> num;
        int i = 1;
        unsigned long long factorial = 1;
        while (i <= num) {
            factorial *= i;
            i++;
        }

        cout << "Factorial of " << num << " is " << factorial << endl;
        cout << "Do you want to calculate another factorial? (1 = Yes, 0 = No): ";
        cin >> choice;
    }

    cout << "Program terminated." << endl;
    return 0;
}

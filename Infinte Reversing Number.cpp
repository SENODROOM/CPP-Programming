#include <iostream>
using namespace std;
int main() {
    int n, rev = 0, rem;
    int option = 1;
    while (option!=-1) {
        cout << "Enter number" << endl;
        cin >> n;
        rev = 0;
        while (n > 0)
        {
            rem = n % 10;
            rev = rev * 10 + rem;
            n = n / 10;
        }
        cout << rev << endl;
        cout << "press -1 if you want to terminate" << endl;
        cin >> option;
    }
}
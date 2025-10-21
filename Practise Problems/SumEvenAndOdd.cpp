#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int even = 0, odd = 0;

    if (n < 0) {
    n = -n;	
	}

    for (int i = n; i > 0; i = i / 10) {
        int digit = i % 10;
        if (digit % 2 == 0)
            even += digit;
        else
            odd += digit;
    }
	cout << "Sum of even digits = " << even << endl;
    cout << "Sum of odd digits = " << odd << endl ;
    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double a , b;
	cout << "Enter first number: " ;
	cin >> a ;
	cout << "Enter second number: ";
	cin >> b ;
	
	b = b+a;
	a = b-a;
	b = b-a;
	cout << "first: " << a << endl ;
	cout << "second: " << b ;
	
    return 0;
}
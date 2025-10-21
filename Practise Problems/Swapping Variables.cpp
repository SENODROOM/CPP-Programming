#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double a , b ,c ;
	cout << "Enter first number: " ;
	cin >> a ;
	cout << "Enter second number: ";
	cin >> b ;
	
	c=b;
	b=a;
	a=c;
	cout << "first: " << a << endl ;
	cout << "second: " << b ;
	
    return 0;
}
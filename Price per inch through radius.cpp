#include <iostream>
using namespace std;

int main(){
    double radius ;
    cout << "Enter the radius: " ;
    cin >> radius ;
    double area = 3.14 * radius * radius ;
    double price ;
    cout << "Enter the price of Pizza: " ;
    cin >> price ;
    double price_per_inch = price / area ;
    cout << "Price per inch: " << price_per_inch ;
	
	return 0; 
}  
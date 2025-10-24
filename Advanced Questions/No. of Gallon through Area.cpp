#include <iostream>
using namespace std;

int main(){
    double height ;
    cout << "Enter the height: " ;
    cin >> height ;
    double width ;
    cout << "Enter the width: " ;
    cin >> width ;
    double coverage_of_paint ;
    cout << "Enter the coverage of paint: " ;
    cin >> coverage_of_paint ;
    double area = height * width ;
    cout << "The number of gallons needed: " << area / coverage_of_paint ; 
    
    return 0;
} 
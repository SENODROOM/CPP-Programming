#include<iostream>
using namespace std;
int main() {
    float area, radius;
    const float pi = 3.145;//named constant
    cin >> radius;
    //pi = 3.666; error
    area = pi * radius * radius;
    cout << "area = " << area << endl;
}
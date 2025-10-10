#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    // Area and Perimeter of Rectangle:
    double lengthR, widthR;
    cout << "Enter the length of Rectangle: ";
    cin >> lengthR;
    cout << "Enter the width of Rectangle: ";
    cin >> widthR;
    if (lengthR == widthR)
    {
        cout << "Rectangle is Square" << endl;
    }
    else
    {
        cout << "Rectangle is not Square" << endl;
    }
    cout << "Area: " << (lengthR * widthR) << endl;
    cout << "Perimeter: " << 2 * (lengthR + widthR) << endl;

    // Area and Perimeter of Triangle:
    double a, b, c;
    cout << "Enter the three sides of triangle:" << endl;
    cin >> a >> b >> c;
    if(a==b && b==c){
        cout << "Triangle is Equilateral" << endl;
    }
    else if (a==b || a==c || b==c){
        cout << "Triangle is Isosceles" << endl;
    }
    else{
        cout << "Triangle is Scalene" << endl;
    }
    double s = (a+b+c)/2;
    double areaT = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Area: " << areaT << endl;
    cout << "Perimeter: " << (a+b+c);
}
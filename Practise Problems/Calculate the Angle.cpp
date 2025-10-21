#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    float angle, a, b, c;
    bool check = true;
    cout << "\t---------Angle of Triangle-----------" << endl;

    do
    {
        cout << "Enter three sides of the triangle : ";
        cin >> a >> b >> c;
        if (a < 0)
        {
            do
            {
                {
                    cout << "Invalid Input---------" << endl;
                    cout << "Enter first side again : ";
                    cin >> a;
                }
            } while (a < 0);
        }
        if (b < 0)
        {
            do
            {
                {
                    cout << "Invalid Input---------" << endl;
                    cout << "Enter second side again : ";
                    cin >> b;
                }
            } while (b < 0);
        }
        if (c < 0)

        {
            do
            {
                cout << "Invalid Input---------" << endl;
                cout << "Enter third side again : ";
                cin >> c;

            } while (c < 0);
        }
        if (a + b > c && a + c > b && c + b > a)
        {
            check = true;
        }
        else
        {
            check = false;
        }
        if (check == false)
        {
            cout << "You given sides are not the sides of triangle .........." << endl;
        }
    } while (check == false);
    angle = acos(((b * b) - (a * a) - (c * c)) / (-2 * a * c));
    cout << "Angle of your triangle is : " << angle;
    cout << "\n\t---------End---------";
    return 0;
}
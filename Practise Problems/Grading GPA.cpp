#include <iostream>
using namespace std;
int main()
{
    double abosolute;
    cout << "Enter your Total Absolutes: ";
    cin >> abosolute;
    if (abosolute >= 90)
    {
        cout << "Grade: A+" << endl;
        cout << "4.00";
    }
    else if (abosolute >= 86 && abosolute < 90)
    {
        cout << "Grade: A" << endl;
        cout << "4.00";
    }
    else if (abosolute >= 82 && abosolute < 86)
    {
        cout << "Grade: A-" << endl;
        cout << "3.67";
    }
    else if (abosolute >= 78 && abosolute < 82)
    {
        cout << "Grade: B+" << endl;
        cout << "3.33";
    }
    else if (abosolute >= 74 && abosolute < 78)
    {
        cout << "Grade: B" << endl;
        cout << "3.00";
    }
    else if (abosolute >= 70 && abosolute < 74)
    {
        cout << "Grade: B-" << endl;
        cout << "2.67";
    }
    else if (abosolute >= 66 && abosolute < 70)
    {
        cout << "Grade: C+" << endl;
        cout << "2.33";
    }
    else if (abosolute >= 62 && abosolute < 66)
    {
        cout << "Grade: C" << endl;
        cout << "2";
    }
    else if (abosolute >= 58 && abosolute < 62)
    {
        cout << "Grade: C-" << endl;
        cout << "1.67";
    }
    else if (abosolute >= 54 && abosolute < 58)
    {
        cout << "Grade: D+" << endl;
        cout << "1.33";
    }
    else if (abosolute >= 50 && abosolute < 54)
    {
        cout << "Grade: D" << endl;
        cout << "1.00";
    }
    else
    {
        cout << "Grade: F" << endl;
        cout << "0.00";
    }

    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    int code;
    cout << "Enter a 5-digit zip code: ";
    cin >> code;
    if (code > 9999 && code< 100000)
    {

        // Provinces:
        int firstdigits = code / 1000;
        if (firstdigits >= 19 && firstdigits <= 29)
        {
            cout << "Provine: KHYBAR PAKHTUNKHWA" << endl;
        }
        if (firstdigits >= 30 && firstdigits <= 64)
        {
            cout << "Provine: PUNJAB" << endl;
        }
        if (firstdigits >= 65 && firstdigits <= 79)
        {
            cout << "Provine: SINDH" << endl;
        }
        if (firstdigits > 82 && firstdigits <= 92)
        {
            cout << "Provine: BALOCHISTAN" << endl;
        }
        if (firstdigits >= 44 && firstdigits <= 45)
        {
            cout << "Islamabad Capital Territory" << endl;
        }

        // Cities:
        if (firstdigits == 74)
            cout << "City: Karachi" << endl;
        else if (firstdigits == 54)
            cout << "City: Lahore" << endl;
        else if (firstdigits == 44)
            cout << "City: Islamabad" << endl;
        else if (firstdigits == 38)
            cout << "City: Faisalabad" << endl;
        else if (firstdigits == 52)
            cout << "City: Gujranwala" << endl;
        else if (firstdigits == 60)
            cout << "City: Multan" << endl;
        else if (firstdigits == 51)
            cout << "City: Sialkot" << endl;
        else if (firstdigits == 65)
            cout << "City: Sukkur" << endl;
        else if (firstdigits == 25)
            cout << "City: Peshawar" << endl;
        else if (firstdigits == 87)
            cout << "City: Quetta" << endl;
        else
            cout << "Unknown ZIP code. City not in database." << endl;
    }
    else
    {
        cout << "Invalid number. Enter a 5-digit number" << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    double litres, kms;
    double totalLitres = 0, totalKms = 0;
    
    cout << "Enter the litres used (-1 to end): ";
    cin >> litres;

    while (litres != -1) {
        cout << "Enter the kilometres driven: ";
        cin >> kms;

        double consumption = (litres / kms) * 100.0;
        cout << "The litres/100km for this tank was " << consumption << endl;

        totalLitres += litres;
        totalKms += kms;

        cout << "Enter the litres used (-1 to end): ";
        cin >> litres;
    }

    if (totalKms > 0) {
        double overall = (totalLitres / totalKms) * 100.0;
        cout << "The overall average consumption was: " << overall << endl;
    } else {
        cout << "No data entered." << endl;
    }

    return 0;
}


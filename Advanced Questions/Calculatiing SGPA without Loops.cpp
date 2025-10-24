#include <iostream>
using namespace std;
int main()
{
    double score1, CrdH1;
    cout << "Enter score in Ideology and Constitution of Pakistan: ";
    cin >> score1;
    cout << "Credit Hours: ";
    cin>> CrdH1;


    double score2, CrdH2;
    cout << "Enter score in IPak Studies: ";
    cin >> score2;
    cout << "Credit Hours: ";
    cin>> CrdH2;


    double score3, CrdH3;
    cout << "Enter score in Functional English: ";
    cin >> score3;
    cout << "Credit Hours: ";
    cin>> CrdH3;


    double score4, CrdH4;
    cout << "Enter score in Functional English Lab: ";
    cin >> score4;
    cout << "Credit Hours: ";
    cin>> CrdH4;


    double score5, CrdH5;
    cout << "Enter score in Programming Fundamentals: ";
    cin >> score5;
    cout << "Credit Hours: ";
    cin>> CrdH5;


    double score6, CrdH6;
    cout << "Enter score in Programming Fundamentals lab: ";
    cin >> score6;
    cout << "Credit Hours: ";
    cin>> CrdH6;


    double score7, CrdH7;
    cout << "Enter score in Applied Physics: ";
    cin >> score7;
    cout << "Credit Hours: ";
    cin>> CrdH7;


    double score8, CrdH8;
    cout << "Enter score in Calculus and Analytical Geometery: ";
    cin >> score8;
    cout << "Credit Hours: ";
    cin>> CrdH8;


    double score9, CrdH9;
    cout << "Enter score in Introduction to Information and Communication Technology: ";
    cin >> score9;
    cout << "Credit Hours: ";
    cin>> CrdH9;

    double GPSH = (score1 * CrdH1) + (score2 * CrdH2) + (score3 * CrdH3) + (score4 * CrdH4) + (score5 * CrdH5) + (score6 * CrdH6) + (score7 * CrdH7) + (score8 * CrdH8) + (score9 * CrdH9);
    double Crdhtotal = CrdH1 + CrdH2 + CrdH3 + CrdH4 + CrdH5 + CrdH6 + CrdH7 + CrdH8 + CrdH9;

    double SGPA = GPSH/Crdhtotal;
    cout << "SGPA: " << SGPA;
}
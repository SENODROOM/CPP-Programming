/*
If his basic salary is less than Rs. 1500,
then HRA = 10% of basic salary and DA = 90% of basic salary.
If his salary is either equal to or above Rs. 1500,
then HRA = Rs. 500 and DA = 98% of basic salary.
If the employee's salary is input through the keyboard
write a program to find his gross salary
*/
#include<iostream>
using namespace std;
int main() {
    float bs,gross;
    do {
        cout << "Input Basic Salary" << endl;
        cin >> bs;
        if (bs < 1500)
        {
            gross = bs + bs * 0.90 + bs * 0.1;
        }
        else {
            gross = bs + 500 + bs * 0.98;
        }
        cout << "Gross salary is :" << gross << endl;
    } while (true);

}
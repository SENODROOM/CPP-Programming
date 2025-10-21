#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int number, sum = 1;
    cout << "\t----------Sum of Odd Numbers----------" << endl;
    cout << "Enter number: ";
    cin >> number;
    if (number < 0)
    {
        do
        {
            cout << "Enter Valid Input-------" << endl;
            cout << "Enter number: ";
            cin >> number;
        } while (number < 0);
    }
    for (int i = 3; i <= number; i++)
    {
        if (i % 2 != 0)
        {
            sum = sum + i;
        }
    }
    cout << "Sum fo first " << number << " odd numbers is :  " << sum << endl;
    cout << "\t ------------End------------" << endl;
    return 0;
}
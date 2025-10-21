#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int num;
    cout << "\t--------Pattern---------" << endl;
    cout << "Enter number : ";
    cin >> num;

    if (num < 0)
    {
        do
        {
            cout << "Invalid input! Please enter a non-negative number." << endl;
            cin >> num;
        } while (num < 0);
    }
    if (num % 2 == 0)
    {
        num /= 2;
    }
    else
    {
        num /= 2;
        num++;
    }
    for (int i = 1; i <= num; i++)
    {
        for (int j = num; j > i; j--)
            cout << "  ";

        for (int k = 1; k <= i; k++)
        {

            cout << k << " ";
        }
        for (int c = i - 1; c >= 1; c--)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    for (int i = (num - 1); i >= 1; i--)
    {
        for (int j = i; j < num; j++)
            cout << "  ";

        for (int k = 1; k <= i; k++)
        {

            cout << k << " ";
        }
        for (int c = i - 1; c >= 1; c--)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}
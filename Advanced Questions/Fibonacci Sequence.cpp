#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int user, sequence = 0, num1 = 0, num2 = 1;
    cout << "\t----------Fibonacci Sequence----------" << endl;
    cout << "Enter number : ";
    cin >> user;
    if (user < 0)
    {
        do
        {
            cout << "Enter Valid Input-------" << endl;
            cout << "Enter number: ";
            cin >> user;
        } while (user < 0);
    }

    for (int i = 0; i < user; i++)
    {
        cout << num1 << " ";
        sequence = num1 + num2;
        num1 = num2;
        num2 = sequence;
    }
    cout << "\n ------------End------------" << endl;
    return 0;
}
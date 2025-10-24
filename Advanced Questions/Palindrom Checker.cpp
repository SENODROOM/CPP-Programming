#include <iostream>
#include <iomanip>
using namespace std;
bool palindrom(int num, bool check, int original)
{
    int reversed = 0, remainder;
    while (num != 0)
    {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }
    if (original == reversed)
    {
        return check = true;
    }
    else
    {
        return check = false;
    }
}
int main()
{
    int num, original;
    bool check = true;

    cout << "\t--------Palindrome Checker---------" << endl;
    cout << "Enter 4-digit number : ";
    cin >> num;

    if (num < 0 || (num < 1000 || num > 10000))
    {
        do
        {
            cout << "Invlid number-------" << endl;
            cout << "Enter 4-digit number : ";
            cin >> num;
        } while (num < 0 || (num < 1000 && num > 10000));
    }
    original = num;

    if (palindrom(num, check, original))
    {
        cout << original << " is palindrome" << endl;
    }
    else
    {
        cout << original << " is not a palindrome" << endl;
    }
    cout << "\t---------End---------";
    return 0;
}
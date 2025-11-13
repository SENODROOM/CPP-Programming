#include <iostream>
using namespace std;

int reverseInt(int num)
{
    int value = 0;
    if (num < 0)
    {
        num *= -1;
        while (num > 0)
        {
            value *= 10;
            int s = num % 10;
            value += s;
            num /= 10;
        }
        return value;
    }
    else
    {
        while (num > 0)
        {
            value *= 10;
            int s = num % 10;
            value += s;
            num /= 10;
        }
        return value;
    }
}

bool checkPalindrome(int num)
{
    bool check = false;
    int rev = reverseInt(num);
    if (num == rev)
    {
        check = true;
    }
    return check;
}
int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    if (checkPalindrome(num))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
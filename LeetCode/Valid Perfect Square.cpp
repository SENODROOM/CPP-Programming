#include <iostream>
using namespace std;

bool isPerfectSquare(int num)
{
    if (num==1)
    {
        return true;
    }
    
    for (int i = 0; i <= num/2; i++)
    {
        if (i*i==num)
        {
            return true;
        }
    }
    
    return false;
}

int main()
{
    int user;
    cout << "Enter the number: ";
    cin >> user;
    if (isPerfectSquare(user))
        cout << "true";
    else
        cout << "false";
}
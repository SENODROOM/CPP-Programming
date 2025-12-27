#include <iostream>
using namespace std;

bool PowerOfTwo(int num)
{
    for (long long i = 1; i <= num; i *= 2)
        if (num == i)
            return true;
    return false;
}

int main()
{
    int user;
    cout << "Enter the number: ";
    cin >> user;
    if (PowerOfTwo(user))
        cout << "true";
    else
        cout << "false";

    return 0;
}